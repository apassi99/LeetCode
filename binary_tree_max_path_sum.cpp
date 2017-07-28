#include <climits>

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
    int maxPathSum(TreeNode* root) {
        
        int s1 = 0, s2 = 0;
        maxPathSumHelper(root, &s1, &s2);
        return max(s1, s2);
    }
    
private:
    // s1 -- sum that can be reused
    // s2 -- sum that can't be reused
    void maxPathSumHelper(TreeNode * root, int *s1, int *s2) {
        
        if (!root) {
            *s1 = INT_MIN / 2;
            *s2 = INT_MIN / 2;
            return;
        }

        if (!root->left && !root->right) {
            *s1 = root->val;
            *s2 = root->val;
            return;
        }
        
        int l_s1 = 0, l_s2 = 0, r_s1 = 0, r_s2 = 0;
        
        maxPathSumHelper(root->left, &l_s1, &l_s2);
        maxPathSumHelper(root->right, &r_s1, &r_s2);
        
        int no_reuse_sum = max(l_s2, r_s2);
        no_reuse_sum = max(no_reuse_sum, l_s1 + root->val + r_s1);
        no_reuse_sum = max(no_reuse_sum, l_s1);
        no_reuse_sum = max(no_reuse_sum, r_s1);
        *s2 = no_reuse_sum;

        *s1 = max(l_s1 + root->val, r_s1 + root->val);
        *s1 = max(*s1, root->val);
    }
};
