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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode * result = NULL;
        subtreeWithAllDeepestHelper(root, &result);
        return result;
    }
    
private:
    
    int subtreeWithAllDeepestHelper(TreeNode * root, TreeNode ** result) {
        
        if (!root)
            return 0;
        
        TreeNode * leftResult = NULL;
        TreeNode * rightResult = NULL;
        
        int leftHeight = subtreeWithAllDeepestHelper(root->left, &leftResult);
        int rightHeight = subtreeWithAllDeepestHelper(root->right, &rightResult);
        
        if (leftHeight == rightHeight) {
            *result = root;
        } else if (leftHeight > rightHeight) {
            *result = leftResult;
        } else {
            *result = rightResult;
        }
        
        return max(leftHeight, rightHeight) + 1;
        
    }
};