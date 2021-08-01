/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        
        helper(root, result);
        
        return result;
    }
private:
    
    int helper(TreeNode* root, int &global_max)
    {
        if (!root)
            return 0;
        
        int left_max  = helper(root->left, global_max);
        int right_max = helper(root->right, global_max);
        
        int returnVal = root->val;
        
        returnVal = max(left_max  + root->val, returnVal);
        returnVal = max(right_max + root->val, returnVal);
        
        int localMax = left_max + right_max + root->val;
        
        global_max = max(localMax, global_max);
        global_max = max(returnVal, global_max);
        
        
        return returnVal;
    }
};