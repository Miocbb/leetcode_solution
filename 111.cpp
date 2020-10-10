#include "include/helper.h"
#include <vector>
#include <iostream>
#include <iostream>

using Helper::TreeNode;
using std::vector;

#include <queue>
using std::queue;

class Solution {
public:
    /**
     * A classic BFS problem.
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int depth = 1;
        queue<TreeNode *> q;
        q.push(root);
        
        while (! q.empty()) {
            int size = q.size();
            // travesal one layer
            for (size_t i = 0; i < size; ++i) {
                auto t = q.front();
                if (t->left == nullptr && t->right == nullptr)
                    return depth;
                
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
                q.pop();
            }
            ++depth;
        }
        return depth;
    }
    
};