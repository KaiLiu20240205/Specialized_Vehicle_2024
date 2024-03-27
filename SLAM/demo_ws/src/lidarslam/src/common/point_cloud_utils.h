#ifndef FC_POINT_CLOUD_UTILS_H
#define FC_POINT_CLOUD_UTILS_H

#include "sensor_msgs/PointCloud2.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <Eigen/SVD>
#include <opencv2/core.hpp>

bool FitPlane(std::vector<Eigen::Matrix<float, 3, 1>>& data, Eigen::Matrix<float, 4, 1>& plane_coeffs, double eps = 1e-2);

pcl::PCLPointCloud2::Ptr fromROSmsgs(const sensor_msgs::PointCloud2ConstPtr& cloud_msg);
pcl::PCLPointCloud2::Ptr VoxelGrid(const pcl::PCLPointCloud2::Ptr cloud);

#endif