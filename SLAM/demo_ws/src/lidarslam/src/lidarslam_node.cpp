#include "ros/ros.h"
#include "common/point_cloud_utils.h"
#include "common/kdtree.h"
#include <chrono>

ros::Publisher pub; 
double total_time(0);
int total_times(0);
pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud_dense(new pcl::PointCloud<pcl::PointXYZI>);
KdTree cloud_old;


void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    auto t1 = std::chrono::high_resolution_clock::now();


    //sensor_msgs的PointCloud2转化为PCL的PointCloud2
    pcl::PCLPointCloud2::Ptr cloud = fromROSmsgs(cloud_msg);
    //检查上一帧cloud_old是否有储存
    if (cloud_old.GetSize()==0)
    {
        // 将PCL的PointCloud2转化为PCL的PointXYZI
        pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
        pcl::fromPCLPointCloud2(*cloud, *pcl_cloud);
        // 去除无效点
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*pcl_cloud, *pcl_cloud_dense, indices);
        cloud_old.BuildTree(pcl_cloud_dense);
    }
    //体素滤波
    pcl::PCLPointCloud2::Ptr cloud_filtered = VoxelGrid(cloud);
    // 将PCL的PointCloud2转化为PCL的PointXYZI
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud_filtered(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromPCLPointCloud2(*cloud_filtered, *pcl_cloud_filtered);
    //并行knn搜索+平面拟合
    int k = 5;
    std::vector<std::pair<size_t, size_t>> matches;
    std::vector<int> index(pcl_cloud_filtered->size());
    for (int i = 0; i < pcl_cloud_filtered->points.size(); ++i) {
        index[i] = i;
    }
    std::for_each(std::execution::par_unseq, index.begin(), index.end(), [&k, &pcl_cloud_filtered](int idx) {
        std::vector<int> closest_idx;
        cloud_old.GetClosestPoint(pcl_cloud_filtered->points[idx], closest_idx, k);
        std::vector<Eigen::Vector3f> points;
        for (int i=0;i<k;i++){
            points.emplace_back(pcl_cloud_dense->points[closest_idx[i]].getArray3fMap());
        }
        Eigen::Vector4f estimated_plane_coeffs;
        if(FitPlane(points,estimated_plane_coeffs)){
        } else {
            //std::cout<< "plane fitting failed"<<std::endl;
        }
    });
    // 将PCL的PointCloud2转化为PCL的PointXYZI
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromPCLPointCloud2(*cloud, *pcl_cloud);
    // 去除无效点
    std::vector<int> indices;
    pcl::removeNaNFromPointCloud(*pcl_cloud, *pcl_cloud_dense, indices);
    //建立KdTree
    cloud_old.BuildTree(pcl_cloud_dense);    
    
    auto t2 = std::chrono::high_resolution_clock::now();
    total_time += std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000;
    total_times++;
    ROS_INFO("average time = %fms",total_time/total_times);
    //发布PCLpointcloud2格式的点云
    sensor_msgs::PointCloud2 output;
    //pcl::toPCLPointCloud2 (*pcl_cloud_dense, *cloud_filtered);
    pcl_conversions::fromPCL(*cloud_filtered, output);
    output.header.frame_id = "vehicle_link";
    // Publish the data
    pub.publish (output);
}

int main (int argc, char** argv)
{

    cloud_old.SetEnableANN();
    // Initialize ROS
    ros::init (argc, argv, "my_pcl_tutorial");
    ros::NodeHandle nh;

    // Create a ROS subscriber for the input point cloud
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2> ("/velodyne_points", 1, cloud_cb);

    // Create a ROS publisher for the output point cloud
    pub = nh.advertise<sensor_msgs::PointCloud2> ("filtered_points", 1);

    // Spin
    ros::spin ();
}
