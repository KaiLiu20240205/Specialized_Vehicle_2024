#include "point_cloud_utils.h"


pcl::PCLPointCloud2::Ptr VoxelGrid_fromROSmsgs(const sensor_msgs::PointCloud2ConstPtr& cloud_msg){
    pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2; 
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    pcl::PCLPointCloud2::Ptr cloud_filtered(new pcl::PCLPointCloud2);

    // Convert to PCL data type
    pcl_conversions::toPCL(*cloud_msg, *cloud);
    
    //Perform the actual filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    sor.setInputCloud (cloudPtr);
    sor.setLeafSize (0.1, 0.1, 0.1);
    sor.filter (*cloud_filtered);


    return cloud_filtered;
}
