#ifndef FC_KDTREE_H
#define FC_KDTREE_H

#include <Eigen/Eigen>
#include <unordered_map>
#include <point_cloud_utils.h>
#include <numeric>


struct KdTreeNode {
    int id_ = 0;                  //节点的索引
    int point_idx_ = -1;            // 点的索引
    int axis_index_ = 0;           // 分割轴
    float split_thresh_ = 0.0;     // 分割位置
    KdTreeNode* left_ = nullptr;   // 左子树
    KdTreeNode* right_ = nullptr;  // 右子树
    bool IsLeaf() const { return left_ == nullptr && right_ == nullptr; }  // 是否为叶子
};

class KDtree{
    public:
    bool BuildTree(const pcl::PointCloud<pcl::PointXYZI>::Ptr& cloud);//建立KDtree  
    void Clear();   //删除记录所有节点的指针
    void Insert(const std::vector<int>& points, KdTreeNode* node);
    void FindSplitAxisAndThresh(const std::vector<int>& point_idx, int& axis, float& th, std::vector<int>& left, std::vector<int>& right);

    
    private:
    std::shared_ptr<KdTreeNode> root_ = nullptr;    // 根节点,kdtree的第一个节点入口
    int tree_node_id_ = 0;  // 为kdtree node 分配id
    std::unordered_map<int, KdTreeNode*> nodes_;    // 记录所有节点
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_;
};

#endif