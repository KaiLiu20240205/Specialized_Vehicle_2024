#ifndef FC_KDTREE_H
#define FC_KDTREE_H

#include <Eigen/Eigen>
#include <map>
#include <point_cloud_utils.h>

class KdTreeNode {
    int id_ = -1;
    int point_idx_ = 0;            // 点的索引
    int axis_index_ = 0;           // 分割轴
    float split_thresh_ = 0.0;     // 分割位置
    KdTreeNode* left_ = nullptr;   // 左子树
    KdTreeNode* right_ = nullptr;  // 右子树
    bool IsLeaf() const { return left_ == nullptr && right_ == nullptr; }  // 是否为叶子
};

class KDtree{
    public:
    bool BuildTree(const pcl::PointCloud<pcl::PointXYZI>::Ptr& cloud);//建立KDtree

    private:
    std::shared_ptr<KdTreeNode> root_ = nullptr;  // 根节点,kdtree的第一个节点入口

};

#endif