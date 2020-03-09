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

    void convertBST(TreeNode *root, int& sum)
    {
        // sum is the summation of all elements larger than root->val.
        if (root == nullptr) return;

        convertBST(root->right, sum);
        root->val += sum;
        sum = root->val;
        convertBST(root->left, sum);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        /**
         * Traversing the BST in-order (RNL) gives the linear access of BST
         * tree elements in a descending order. Folowing this thinking,
         * we can traverse the tree in the descending order and keep the
         * summation of all visited values in a record. Then add the summation
         * value into the current node value.
         */
        if (root == nullptr) return nullptr;

        int sum = 0;
        convertBST(root, sum);
        return root;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    // a = {3,9,20,-1,-1,15,7};
    a = {5, 2, 13};
    Solution solution;
    TreeNode *tree = create_binary_tree_from_vector(a);
    std::cout << "Original tree: ";
    auto layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    solution.convertBST(tree);
    std::cout << "updated tree: ";
    layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;

    // std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
