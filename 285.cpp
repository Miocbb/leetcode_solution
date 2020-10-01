#include "include/helper.h"
#include <stack>
#include <vector>

using Helper::TreeNode;

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right != NULL) {
            p = p->right;
            while (p->left != NULL)
            {
                p = p->left;
            }
            return p;
        }
        else {
            std::stack<TreeNode *> s;
            while (!s.empty() || root != NULL)
            {
                // keep going deeper and deeper in the left branches.
                // Push non-NULL left branches into stack.
                if (root != NULL) {
                    s.push(root);
                    root = root->left;
                } else {
                // when we found left branch is NULL, we know we are at
                // the end of left branch.

                    // at root
                    root = s.top();
                    s.pop();

                    // process at root
                    if (root->val == p->val) {
                        if (!s.empty()) {
                            return s.top();
                        } else {
                            return NULL;
                        }
                    }

                    // go to right
                    root = root->right;
                }
            }
            return NULL;
        }
    }
};

TreeNode* get_node_by_value(TreeNode *root, int val) {
    if (root == NULL) {
        return NULL;
    } else {
        auto t = get_node_by_value(root->left, val);
        if (t != NULL) {
            return t;
        }
        if (root->val == val) {
             return root;
        }
        auto t2 = get_node_by_value(root->right, val);
        if (t2 != NULL) {
            return t2;
        }
    }
}

int main(int argc, const char** argv) {

    std::vector<int> a {2, 1, 3};

    TreeNode* root = Helper::create_binary_tree_from_vector(a);
    TreeNode* p = get_node_by_value(root, 3);
    std::cout << p->val << std::endl;
    if (p == NULL) {
        std::cout << "No results\n";
    } else {
    }
    auto rst = Solution().inorderSuccessor(root, p);
    if (rst != NULL)
        std::cout << rst->val << std::endl;
    else
        std::cout << "NO results";

    return 0;
}
