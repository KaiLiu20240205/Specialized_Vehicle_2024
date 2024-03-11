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

    // 将PCL的PointCloud2转化为PCL的PointXYZI
    pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>);
    pcl::fromPCLPointCloud2(*cloud_filtered, *pcl_cloud);

    //建立KDtree
    KDtree cloud1;
    cloud1.BuildTree(pcl_cloud);


    auto t2 = std::chrono::high_resolution_clock::now();
    total_time += std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000;
    total_times++;
    ROS_INFO("average time = %fms",total_time/total_times);

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    //pcl_conversions::fromPCL(*cloud_filtered, output);
    pcl::toROSMsg(*pcl_cloud, output);
    output.header.frame_id = "vehicle_link";
    // Publish the data
    pub.publish (output);
    
}

int main (int argc, char** argv)
{
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
