#include "include/helper.h"
#include <vector>
#include <iostream>

using Helper::TreeNode;
using std::vector;


class Solution {
public:
    int height(TreeNode *root) {
        if (root) {
            return std::max(height(root->left), height(root->right)) + 1;
        }
        return 0;
    }

    bool isBalanced(TreeNode* root) {
        if (root) {
            if (abs(height(root->left) - height(root->right)) > 1)
                return false;
            
            if (! isBalanced(root->left))
                return false;

            if (! isBalanced(root->right))
                return false;
            return true;
        }
        return true;        
    }
};

int main(int argc, const char** argv) {
    vector<int> v {1,2,2,3,3,-1,-1,4,4};
    TreeNode* root = Helper::create_binary_tree_from_vector(v);
    Solution s;
    std::cout << s.height(root) << std::endl;

    std::cout << s.isBalanced(root);
    return 0;
}