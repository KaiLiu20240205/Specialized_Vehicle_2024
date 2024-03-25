#include "ros/ros.h"
#include "common/point_cloud_utils.h"
#include "common/kdtree.h"
#include <chrono>

ros::Publisher pub; 
double total_time(0);
int total_times(0);

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    //sensor_msgs的PointCloud2转化为PCL的PointCloud2并体素滤波
    pcl::PCLPointCloud2::Ptr cloud_filtered = VoxelGrid_fromROSmsgs(cloud_msg);

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    pcl_conversions::fromPCL(*cloud_filtered, output);
    output.header.frame_id = "vehicle_link";
    // Publish the data
    pub.publish (output);

    // 将PCL的PointCloud2转化为PCL的PointXYZI
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    
    pcl::fromPCLPointCloud2(*cloud_filtered, *pcl_cloud);
    
    // 去除无效点
    std::vector<int> indices;
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud_dense(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::removeNaNFromPointCloud(*pcl_cloud, *pcl_cloud_dense, indices);

    //建立KDtree
    KDtree cloud1;
    std::vector<int> closest_idx;
    cloud1.BuildTree(pcl_cloud_dense);
    cloud1.GetClosestPoint(pcl_cloud_dense->points[0],closest_idx);
    
    auto t2 = std::chrono::high_resolution_clock::now();
    total_time += std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000;
    total_times++;
    ROS_INFO("average time = %fms",total_time/total_times);

    
}

int main (int argc, char** argv)
{
    // pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
    // pcl::PointXYZI p1, p2, p3, p4;
    // p1.x = 0;
    // p1.y = 0;
    // p1.z = 0;

    // p2.x = 1;
    // p2.y = 0;
    // p2.z = 0;

    // p3.x = 0;
    // p3.y = 1;
    // p3.z = 0;

    // p4.x = 1;
    // p4.y = 1;
    // p4.z = 0;

    // cloud->points.push_back(p1);
    // cloud->points.push_back(p2);
    // cloud->points.push_back(p3);
    // cloud->points.push_back(p4);

    // KDtree kdtree;
    // kdtree.BuildTree(cloud);
    // kdtree.PrintAll();
    
    
    // Initialize ROS
    ros::init (argc, argv, "my_pcl_tutorial");
    ros::NodeHandle nh;

    // Create a ROS subscriber for the input point cloud
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2> ("/sensor/lidar16/top/pointcloud", 1, cloud_cb);

    // Create a ROS publisher for the output point cloud
    pub = nh.advertise<sensor_msgs::PointCloud2> ("filtered_points", 1);

    // Spin
    ros::spin ();
}
