#include <list>

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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        list<TreeNode *> q;

        if (root) q.push_back(root);
        
        while (q.size() > 0) {
            int len = q.size();
            double sum = 0;
            
            for (int i = 0; i < len; i++) {
                TreeNode * n = q.front();
                q.pop_front();
                sum += (double) n->val;
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            double avg = sum / (double (len));
            result.push_back(avg);
        }
        
        return result;
    }
};
