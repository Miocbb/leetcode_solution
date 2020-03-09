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
    /**
     * helper function.
     * @param t: path string to current root.
     * if current root is a leaf, save path string into result.
     * else recursively form path to root.left and root.right.
     */
    void binaryTreePaths(vector<string> &result, TreeNode *root, string t)
    {
        if (!root->left && !root->right) {
            result.push_back(t);
            return;
        }

        if (root->left)
            binaryTreePaths(result, root->left,
                            t + "->" + to_string(root->left->val));
        if (root->right)
            binaryTreePaths(result, root->right,
                            t + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return result;

        binaryTreePaths(result, root, to_string(root->val));
        return result;
    }

    vector<string> binaryTreePaths2(TreeNode *root)
    {
        /**
         * pre-order tranverse the tree.
         * Record the path of each node in an auxiliary stack.
         *
         * Following the pre-order traversal order: root->left->right:
         * At each node, first check the root node is a leaf or not.
         * If it is a leaf, push its path into the results.
         * Second traverse the root.left and root.right. Along pushing the
         * root.left and root.right into stack, record its path based on root
         * path and save it in the auxiliary stack.
         */
        vector<string> result;
        if (!root)
            return result;

        stack<TreeNode *> s_node;
        stack<string> s_path;
        s_node.push(root);
        s_path.push(to_string(root->val));

        while (!s_node.empty()) {
            string path = s_path.top();
            TreeNode *node = s_node.top();
            s_path.pop();
            s_node.pop();

            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
            }
            if (node->right != nullptr) {
                s_node.push(node->right);
                s_path.push(path + "->" + to_string(node->right->val));
            }
            if (node->left != nullptr) {
                s_node.push(node->left);
                s_path.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    // a = {3,9,20,-1,-1,15,7};
    a = {1, 2, 3, 4, 5};
    Solution solution;
    TreeNode *tree = create_binary_tree_from_vector(a);
    std::cout << "Original tree: ";
    auto layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    auto rst = solution.binaryTreePaths(tree);
    rst = solution.binaryTreePaths2(tree);
    for (auto i : rst) {
        std::cout << i << " ";
    }

    // std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
