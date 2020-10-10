/**
 * Definition for a binary tree node.
 */

#include <vector>
#include <cstddef>

using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:    
    vector<TreeNode *> next_layer(vector<TreeNode*> l) {
        vector<TreeNode *> rst;
        for (size_t i = 0; i < l.size(); ++i) {
            if (l[i]) {
                if (l[i]->left)
                    rst.push_back(l[i]->left);
                if (l[i]->right)
                    rst.push_back(l[i]->right);
            }
        }
        return rst;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        vector<TreeNode*> inp;
        inp.push_back(root);
        
        vector<TreeNode *> pre = inp;
        vector<TreeNode *> cur = inp;
        while(cur.size()) {
            vector<int> t;
            for (size_t i = 0; i < cur.size(); ++i) {
                if (cur[i])
                    t.push_back(cur[i]->val);
            }
            if (t.size())
                rst.push_back(t);
            pre = cur;
            cur = next_layer(cur);
        }
        
        return rst;
    }
};