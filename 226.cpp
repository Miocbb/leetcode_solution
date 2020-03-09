#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::stack;
using std::queue;

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
    if (root == nullptr) return rst;

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
            q_layer.push(l+1);
            q_node.push(node->right);
            q_layer.push(l+1);
        }
    }
    return rst;
}

class Solution {
  public:
    TreeNode *rst(TreeNode *root)
    {
        /**
         * recursive solution.
         * Inversion of the tree at root means: first swap the left and right
         * child, then invert at root.left and root.right recursively.
         */
        if (root == nullptr) return nullptr;

        auto tem = root->left;
        root->left = root->right;
        root->right = tem;
        rst(root->left);
        rst(root->right);
        return root;
    }

    TreeNode *iterative_rst(TreeNode *root)
    {
        /**
         * Solve the problem iteratively, in a manner similar to breadth-first
         * search.
         *
         */
        if (root == nullptr) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node != nullptr) {
                q.push(node->left);
                q.push(node->right);

                auto tem = node->left;
                node->left = node->right;
                node->right = tem;
            }
        }
        return root;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    //a = {3,9,20,-1,-1,15,7};
    a = {1, 2, 3, 4, 5};
    Solution solution;
    TreeNode * tree = create_binary_tree_from_vector(a);
    std::cout << "Original tree: ";
    auto layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    solution.rst(tree);

    std::cout << "Inverted tree: ";
    layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    tree = create_binary_tree_from_vector(a);
    std::cout << "Original tree: ";
    layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    solution.iterative_rst(tree);

    std::cout << "Inverted tree: ";
    layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    //std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
