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
    TreeNode* convertBST(TreeNode* root) {
        
        if (!root) {
            return root;
        }
        
        int sum = findSum(root);
        convertBST_helper(root, &sum);
        return root;
    }
    
private:
    
    int findSum(TreeNode *root) {
        
        if (!root)
            return 0;
        
        return root->val + findSum(root->left) + findSum(root->right);
    }
    
    void convertBST_helper(TreeNode* root, int * sum) {
        
        if (!root) {
            return;
        }
        
        convertBST_helper(root->left, sum);
        
        *sum = *sum - root->val;
        root->val = root->val + *sum;
        
        convertBST_helper(root->right, sum);

    }
};