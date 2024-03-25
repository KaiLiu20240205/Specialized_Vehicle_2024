#ifndef FC_KDTREE_H
#define FC_KDTREE_H

#include <Eigen/Eigen>
#include <unordered_map>
#include <point_cloud_utils.h>
#include <numeric>
//#include "ros/ros.h"
#include <queue>
#include <iostream>


struct KdTreeNode {
    int id_ = 0;                  //节点的索引
    int point_idx_ = -1;            // 点的索引
    int axis_index_ = 0;           // 分割轴
    float split_thresh_ = 0.0;     // 分割位置
    KdTreeNode* left_ = nullptr;   // 左子树
    KdTreeNode* right_ = nullptr;  // 右子树
    bool IsLeaf() const { return left_ == nullptr && right_ == nullptr; }  // 是否为叶子
};

/// 用于记录knn结果
struct NodeAndDistance {
    NodeAndDistance(KdTreeNode* node, float dis2) : node_(node), distance2_(dis2) {}
    KdTreeNode* node_ = nullptr;
    float distance2_ = 0;  // 平方距离，用于比较

    bool operator<(const NodeAndDistance& other) const { return distance2_ < other.distance2_; }
};

class KDtree{
    public:
    bool BuildTree(const pcl::PointCloud<pcl::PointXYZI>::Ptr& cloud);// 建立KDtree  
    void Clear();   // 删除记录所有节点的指针
    void Insert(const std::vector<int>& points, KdTreeNode* node);
    bool GetClosestPoint(const pcl::PointXYZI& pt, std::vector<int>& closest_idx, int k = 5); // 获取k近邻
    void PrintAll();

    private:
    int k_;                                         // k近邻搜索数量                
    int size_;                                      // 叶子节点数量
    std::shared_ptr<KdTreeNode> root_ = nullptr;    // 根节点,kdtree的第一个节点入口
    int tree_node_id_ = 0;  // 为kdtree node 分配id
    std::unordered_map<int, KdTreeNode*> nodes_;    // 记录所有节点
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_;
    static inline float Dis2(const Eigen::Vector3f& p1, const Eigen::Vector3f& p2) { return (p1 - p2).squaredNorm(); }
    void FindSplitAxisAndThresh(const std::vector<int>& point_idx, int& axis, float& th, std::vector<int>& left, std::vector<int>& right);
    void Knn(const Eigen::Vector3f &pt, KdTreeNode *node, std::priority_queue<NodeAndDistance> &knn_result) const;
    void ComputeDisForLeaf(const Eigen::Vector3f &pt, KdTreeNode *node,std::priority_queue<NodeAndDistance> &knn_result) const;
    bool NeedExpand(const Eigen::Vector3f& pt, KdTreeNode* node, std::priority_queue<NodeAndDistance>& knn_result) const;

};

#endif