#include "include/helper.h"
#include <vector>
#include <iostream>

using Helper::TreeNode;
using std::vector;


class Solution {
    vector<int> array_;
    void to_array(TreeNode *root) {
        if (root) {
            to_array(root->left);
            array_.push_back(root->val);
            to_array(root->right);
        }
    }

    int n_;
    bool found_;
    int val_;

    void travesal(TreeNode *root, int k) {
        if (found_) return;

        if (root) {
            travesal(root->left, k);
            n_++;
            //printf("n: %d val: %d\n", n_, root->val);
            if (n_ == k) {
                found_ = true;
                val_ = root->val;
                return;
            }
            travesal(root->right, k);
        }
       
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        to_array(root);
        if (array_.size())
            return array_[k-1];
        else
            return 0;
    }
    int kthSmallest2(TreeNode* root, int k) {
        n_ = 0;
        found_ = false;
        travesal(root, k);
        return val_;
    }
};

int main(int argc, const char** argv) {
    vector<int> v {3,1,4,-1,2};
    TreeNode* root = Helper::create_binary_tree_from_vector(v);
    Solution s;
    std::cout << s.kthSmallest(root, 1) << std::endl;
    std::cout << s.kthSmallest2(root, 1) << std::endl;

    return 0;
}