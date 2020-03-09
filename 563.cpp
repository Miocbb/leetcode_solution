#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using std::queue;
using std::stack;
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

void show_tree_layers(vector<vector<int>> layers)
{
    for (auto l : layers) {
        std::cout << "[";
        for (auto i : l) {
            std::cout << i << " ";
        }
        std::cout << "],";
    }
}

vector<vector<int>> get_layers_of_tree(TreeNode *root)
{
    vector<vector<int>> rst;
    if (root == nullptr)
        return rst;

    queue<TreeNode *> q_node;
    queue<size_t> q_layer;
    q_node.push(root);
    q_layer.push(0);
    size_t curr_layer = 0;
    vector<int> v_layer;

    while (!q_node.empty()) {
        auto node = q_node.front();
        auto l = q_layer.front();
        q_node.pop();
        q_layer.pop();
        if (curr_layer != l) {
            curr_layer = l;
            rst.push_back(v_layer);
            v_layer.clear();
        }
        if (node != nullptr)
            v_layer.push_back(node->val);

        if (node != nullptr) {
            q_node.push(node->left);
            q_layer.push(l + 1);
            q_node.push(node->right);
            q_layer.push(l + 1);
        }
    }
    return rst;
}

using std::to_string;
class Solution {
  public:
    void post_order(TreeNode *root)
    {
        if (root == nullptr) return;

        post_order(root->left);
        post_order(root->right);
        if (root->left != nullptr)
            root->val += root->left->val;
        if (root->right != nullptr)
            root->val += root->right->val;
    }

    int findTilt(TreeNode *root)
    {
        /**
         * 1. Do a post-order traversal of the tree to update the tree, so that
         * echo node value is the summation of all left subtree values and
         * all right subtree values.
         * 2. Do a layer-wise traversal from the top to bottom. The value of
         * each node is the absolute difference node.left and node.right.
         * Along the layer-wise traversal, add up the node values, which gives
         * the final answer.
         */

        if (root == nullptr) return 0;
        // 1 step.
        post_order(root);

        // 2nd step.
        int ans = 0;
        queue<TreeNode *> q_node;
        q_node.push(root);
        while (!q_node.empty())
        {
            auto node = q_node.front();
            q_node.pop();
            if (node != nullptr) {
                int left_val = (node->left == nullptr ? 0 : node->left->val);
                int right_val = (node->right == nullptr ? 0 : node->right->val);
                node->val = std::abs(left_val - right_val);
                ans += node->val;
                q_node.push(node->left);
                q_node.push(node->right);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    // a = {3,9,20,-1,-1,15,7};
    a = {1,2,3,4,5, 6, 7};
    //a = {1,2};
    Solution solution;
    TreeNode *tree = create_binary_tree_from_vector(a);
    std::cout << "Original tree: ";
    auto layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;
    std::cout << solution.findTilt(tree);
    // std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
