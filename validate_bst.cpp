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
    bool isValidBST(TreeNode* root) {
        
        return isValidBST_helper(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool isValidBST_helper(TreeNode* root, long min, long max) {
        if (!root)
            return true;
        
        if (root->val <= min || root->val >= max)
            return false;
            
        return isValidBST_helper(root->left, min, root->val) && isValidBST_helper(root->right, root->val, max);
    }
};
