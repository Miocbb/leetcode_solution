#ifndef __LEETCODE_HELPER_H__
#define __LEETCODE_HELPER_H__

#include <cstddef>
#include <iostream>
#include <vector>

inline void show_vec(std::vector<int> &nums)
{
    for (auto i : nums) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

namespace Helper {
using std::vector;

inline void show_vec(std::vector<int> &nums)
{
    for (auto i : nums) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_binary_tree_from_vector(vector<int> &a)
{
    if (a.size() == 0)
        return NULL;

    vector<TreeNode *> nodes;
    for (size_t i = 0; i < a.size(); ++i) {
        TreeNode *node = NULL;
        if (a[i] != -1)
            node = new TreeNode(a[i]);
        nodes.push_back(node);
    }
    size_t size = nodes.size();
    for (size_t i = 0; i < nodes.size(); ++i) {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        if (nodes[i] != NULL) {
            nodes[i]->left = (left >= size ? NULL : nodes[left]);
            nodes[i]->right = (right >= size ? NULL : nodes[right]);
        }
    }
    return nodes[0];
}

void delete_binary_tree(TreeNode *root)
{
    if (root != NULL) {
        delete_binary_tree(root->left);
        delete_binary_tree(root->right);
    }
    delete root;
}

} // namespace Helper
#endif // __LEETCODE_HELPER_H__
