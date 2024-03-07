#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <chrono>

void callback(const sensor_msgs::PointCloud2ConstPtr & in_cloud_ptr)
{
	auto t1 = std::chrono::high_resolution_clock::now();

    // 将sensor_msgs的PointCloud2转化为PCL的PointXYZ
	pcl::PointCloud<pcl::PointXYZ>::Ptr colorcloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*in_cloud_ptr, *colorcloud);

    // 体素滤波
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::VoxelGrid<pcl::PointXYZ> sor;
    sor.setInputCloud (colorcloud);
    sor.setLeafSize (0.1, 0.1, 0.1);
    sor.filter (*cloud_filtered);

    auto t2 = std::chrono::high_resolution_clock::now();
    double total_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000;
    ROS_INFO("time = %fms",total_time);
}

ros::Publisher pub; 

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    // Container for original & filtered data
    pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2; 
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    pcl::PCLPointCloud2 cloud_filtered;

    // Convert to PCL data type
    pcl_conversions::toPCL(*cloud_msg, *cloud);
    
    //Perform the actual filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    sor.setInputCloud (cloudPtr);
    sor.setLeafSize (0.1, 0.1, 0.1);
    sor.filter (cloud_filtered);

    // 将PCL的PointCloud2转化为PCL的PointXYZ
    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(cloud_filtered, *pcl_cloud);

    auto t2 = std::chrono::high_resolution_clock::now();
    double total_time = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() * 1000;
    ROS_INFO("time = %fms",total_time);

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    pcl_conversions::fromPCL(*cloud, output);
    output.header.frame_id = "vehicle_link";
    // Publish the data
    pub.publish (output);

}

int
main (int argc, char** argv)
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
