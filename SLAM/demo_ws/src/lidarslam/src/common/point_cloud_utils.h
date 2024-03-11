#ifndef FC_POINT_CLOUD_UTILS_H
#define FC_POINT_CLOUD_UTILS_H

#include "sensor_msgs/PointCloud2.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

pcl::PCLPointCloud2::Ptr VoxelGrid_fromROSmsgs(const sensor_msgs::PointCloud2ConstPtr& cloud_msg);

#endif