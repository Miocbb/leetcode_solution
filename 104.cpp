#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_binary_tree_from_vector(vector<int> &a)
{
    if (a.size() == 0) return NULL;

    vector<TreeNode *> nodes;
    for (size_t i = 0; i < a.size(); ++i) {
        TreeNode *node  = NULL;
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

class Solution {
  public:
    int rst(TreeNode *root)
    {
        /**
         * Straight-forward recursive solution. The maximum depth at node i
         * D(i) can be get as
         * D(i) = max{D(i.left), D(i.right)} + 1.
         */
        if (root == NULL) return 0;
        else return std::max(rst(root->left), rst(root->right)) + 1;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    a = {3,9,20,-1,-1,15,7};
    TreeNode * tree = create_binary_tree_from_vector(a);
    Solution solution;
    std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
