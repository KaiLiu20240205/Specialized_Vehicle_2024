#include "kdtree.h"



bool KDtree::BuildTree(const pcl::PointCloud<pcl::PointXYZI>::Ptr& cloud)
{
    
    if (cloud->empty()) {
        return false;
    }
    
    root_.reset(new KdTreeNode()); //每次建树时创建一个新的根节点。
    Clear();                       //清理上一次建数的指针及其对象。
    cloud_ = cloud;

    std::vector<int> idx(cloud->size());
    for (int i = 0; i < cloud->points.size(); ++i) {
        idx[i] = i;
    }
    cloud->points[0].getArray3fMap();
    Insert(idx, root_.get());
    return true;
}

void KDtree::Clear()
{
    for (const auto &np : nodes_) {
        if (np.second != root_.get()) {
            delete np.second;
        }
    }
}

void KDtree::Insert(const std::vector<int> &points, KdTreeNode *node)
{
    nodes_.insert({node->id_, node});
    if (points.empty()) {
        return;
    }

    if (points.size() == 1) {
        node->point_idx_ = points[0];
        return;
    }

    std::vector<int> left, right;

    FindSplitAxisAndThresh(points, root_->axis_index_, root_->split_thresh_, left, right);

    const auto create_if_not_empty = [&node, this](KdTreeNode *&new_node, const std::vector<int> &index) {
        if (!index.empty()) {
            new_node = new KdTreeNode;
            new_node->id_ = tree_node_id_++;
            Insert(index, new_node);
        }
    };

    create_if_not_empty(node->left_, left);
    create_if_not_empty(node->right_, right);
}

void KDtree::FindSplitAxisAndThresh(const std::vector<int> &point_idx, int &axis, float &th, std::vector<int> &left, std::vector<int> &right)
{
    Eigen::Vector3f var;
    Eigen::Vector3f mean;
    int len = point_idx.size();
    mean = std::accumulate(point_idx.begin(),point_idx.end(),Eigen::Vector3f::Zero().eval(),[this](const Eigen::Vector3f &acc, const int &idx){return acc+cloud_->points[idx].getVector3fMap();})/len;
    var = std::accumulate(point_idx.begin(),point_idx.end(),Eigen::Vector3f::Zero().eval(),[&mean,this](const Eigen::Vector3f &acc, const int &idx){return acc+(cloud_->points[idx].getVector3fMap()-mean).cwiseAbs2();})/(len-1);    
    int max_i, max_j;
    var.maxCoeff(&max_i, &max_j);
    axis = max_i;
    th = mean[axis];

    for (const auto &idx : point_idx) {
        if (cloud_->points[idx].getVector3fMap()[axis] < th) {
            left.emplace_back(idx);
        } else {
            right.emplace_back(idx);
        }
    }

    
}
