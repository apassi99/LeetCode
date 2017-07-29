#include <list>
#include <climits>

using std::list;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        list<TreeNode *> q;
        vector<int> result;
        
        if (root) q.push_back(root);
        
        while (q.size() > 0) {
            int len = q.size();
            int max = INT_MIN;
            
            for (int i = 0; i < len; i++) {
                TreeNode * n = q.front();
                q.pop_front();
                
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
                if (n->val > max) max = n->val;
            }
            
            result.push_back(max);
        }
        
        return result;
    }
};
