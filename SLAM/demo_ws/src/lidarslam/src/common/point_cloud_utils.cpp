#include "point_cloud_utils.h"



bool FitPlane(std::vector<Eigen::Matrix<float, 3, 1>>& data, Eigen::Matrix<float, 4, 1>& plane_coeffs, double eps) {
    if (data.size() < 3) {
        return false;
    }

    Eigen::MatrixXf A(data.size(), 4);
    for (int i = 0; i < data.size(); ++i) {
        A.row(i).head<3>() = data[i].transpose();
        A.row(i)[3] = 1.0;
    }

    Eigen::JacobiSVD<Eigen::MatrixXf> svd(A, Eigen::ComputeThinV);
    plane_coeffs = svd.matrixV().col(3);

    // check error eps
    for (int i = 0; i < data.size(); ++i) {
        double err = plane_coeffs.template head<3>().dot(data[i]) + plane_coeffs[3];
        if (err * err > eps) {
            return false;
        }
    }

    return true;
}

pcl::PCLPointCloud2::Ptr fromROSmsgs(const sensor_msgs::PointCloud2ConstPtr& cloud_msg){
    pcl::PCLPointCloud2::Ptr cloud(new pcl::PCLPointCloud2); 
    // Convert to PCL data type
    pcl_conversions::toPCL(*cloud_msg, *cloud);
    return cloud;
}

pcl::PCLPointCloud2::Ptr VoxelGrid(const pcl::PCLPointCloud2::Ptr cloud){
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    pcl::PCLPointCloud2::Ptr cloud_filtered(new pcl::PCLPointCloud2); 
    sor.setInputCloud (cloudPtr);
    sor.setLeafSize (0.1, 0.1, 0.1);
    sor.filter (*cloud_filtered);
    return cloud_filtered;
}