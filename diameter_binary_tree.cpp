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
    int diameterOfBinaryTree(TreeNode* root) {
        int d1 = 0, d2 = 0;
        diameterOfBinaryTree_helper(root, &d1, &d2);
        return max(d1, d2);
    }
    
private:
    
    // d1 - diameter that can be reused
    // d2 - diameter that can't be reused
    void diameterOfBinaryTree_helper(TreeNode * root, int * d1, int * d2) {
        
        if (!root || (!root->left && !root->right) ) {
            *d1 = 0;
            *d2 = 0;
            return;
        }
        
        int l_d1 = 0, l_d2 = 0, r_d1 = 0, r_d2 = 0;
        
        diameterOfBinaryTree_helper(root->left, &l_d1, &l_d2);
        diameterOfBinaryTree_helper(root->right, &r_d1, &r_d2);
        
        *d1 = max(l_d1 + 1, r_d1 + 1);
        int no_reuse_d = max(l_d2, r_d2);
        
        if (root->left && root->right)
            no_reuse_d = max(no_reuse_d, l_d1 + r_d1 + 2);
        
        *d2 = no_reuse_d;
        
    }
};