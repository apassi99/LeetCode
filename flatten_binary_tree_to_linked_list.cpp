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
    void flatten(TreeNode* root) {
        
        TreeNode * end = NULL;
        flattenHelper(root, end);
    }
    
private:
    
    void flattenHelper(TreeNode * &root, TreeNode * &end) {

        if (!root) return;
        
        if (!root->left && !root->right) {
            end = root;
            return;
        }
        
        TreeNode * end_left = NULL;
        TreeNode * end_right = NULL;
        
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        
        flattenHelper(root->left, end_left);
        flattenHelper(root->right, end_right);
        
        if (left && end_left) {
            root->right = left;
            end_left->right = right;
        }
        
        root->left = NULL;
        end = (end_right) ? end_right : end_left;
    }
};