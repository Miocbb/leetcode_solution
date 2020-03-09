#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using std::string;
using std::vector;
using std::stack;

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
    bool rst(TreeNode *root, int sum)
    {
        /**
         * Basically, this problem can be converted into a problem that
         * traverse the tree in a pre-order.
         * At each node, subtract the value in current node from the sum.
         * Then work the node.left and node.right to see if any of them
         * can solve the problem.
         */
        if (root == NULL)
            return false;
        else {
            int t = sum - root->val;
            if (t == 0 && root->right == NULL && root->left == NULL)
                return true;
            else
                return rst(root->left, t) || rst(root->right, t);
        }
    }

    bool iterative_rst(TreeNode *root, int sum)
    {
        // Traverse the tree by root->left->right. Implement it with stack
        // by iterative method. Use a stack to store the corresponding sum target
        // for each node in the stack.
        if (root == NULL)
            return false;

        stack<TreeNode *> s;
        stack<int > sum_val;
        s.push(root);
        // This stack stores the new sum number for all the nodes in stack s.
        sum_val.push(sum - root->val);
        while (!s.empty()) {
            TreeNode * node = s.top();
            int new_sum = sum_val.top();
            s.pop();
            sum_val.pop();
            // do operations on the current node.
            if (new_sum == 0 && node->right == NULL && node->left == NULL)
                return true;
            // traverse left and right sub-tree.
            if (node->right != NULL) {
                s.push(node->right);
                sum_val.push(new_sum - node->right->val);
            }
            if (node->left != NULL) {
                s.push(node->left);
                sum_val.push(new_sum - node->left->val);
            }
        }
        return false;
    }

    bool iterative_rst2(TreeNode *root, int sum)
    {
        // Traverse the tree by root->left->right. At each node, add its
        // parent value into itself.
        // Now just check the leaves to see if there is any one equal to target
        // sum.
        if (root == NULL)
            return false;

        stack<TreeNode *> s;
        stack<int > sum_val;
        s.push(root);
        while (!s.empty()) {
            TreeNode * node = s.top();
            s.pop();
            // do operations on the current node.
            if (node->val == sum && node->right == NULL && node->left == NULL)
                return true;
            // traverse left and right sub-tree.
            if (node->right != NULL) {
                s.push(node->right);
                node->right->val += node->val;
            }
            if (node->left != NULL) {
                s.push(node->left);
                node->left->val += node->val;
            }
        }
        return false;

    }
};

int main()
{
    vector<int> a = {1, 2};
    //a = {3,9,20,-1,-1,15,7};
    TreeNode * tree = create_binary_tree_from_vector(a);
    Solution solution;
    std::cout << solution.rst(tree, 1) << std::endl;
    std::cout << solution.iterative_rst(tree, 1) << std::endl;
    std::cout << solution.iterative_rst2(tree, 1) << std::endl;

    delete_binary_tree(tree);
}
