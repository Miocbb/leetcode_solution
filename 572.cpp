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
    bool isSubTreeChecker(TreeNode *root1, TreeNode *root2)
    {
        /**
         * compare if two trees are the same based on pre-order traversal.
         *
         * Time complexity: O(min(N1, N2))
         */
        if (root1 == nullptr && root2 == nullptr) return true;
        else if (root1 != nullptr && root2 != nullptr) {
            if (root1->val != root2->val)
                return false;
            return isSubTreeChecker(root1->left, root2->left) &&
                isSubTreeChecker(root1->right, root2->right);
        } else return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *root2)
    {
        /**
         * Do a pre-order traversal. At each node compare the subtree with target
         * tree root2.
         *
         * Time complexity: O(N1 * min(N1, N2))
         */
        if (root2 == nullptr) return true;
        else if (root != nullptr && root2 != nullptr) {
            if (isSubTreeChecker(root, root2)) return true;
            return isSubtree(root->left, root2) || isSubtree(root->right, root2);
        } else
            return false;
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    // a = {3,9,20,-1,-1,15,7};
    a = {3, 4, 5,1,2,6,7,0};
    vector<int> a2 = {4, 1,2, 0};
    //a2 = {3, 4, 5, 1,2,6, 7,0};
    //a = {1,2};
    a = {1, 1};
    a2 = {1};
    Solution solution;
    TreeNode *tree = create_binary_tree_from_vector(a);
    TreeNode *tree2 = create_binary_tree_from_vector(a2);
    std::cout << "Original tree: ";
    auto layers = get_layers_of_tree(tree);
    show_tree_layers(layers);
    std::cout << std::endl;
    std::cout << solution.isSubtree(tree, tree2);
    // std::cout << solution.rst(tree) << std::endl;

    delete_binary_tree(tree);
}
