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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if (!t1 && !t2) {
            return NULL;
        }
        
        TreeNode * n = new TreeNode(0);
        
        TreeNode * t1_left = NULL;
        TreeNode * t2_left = NULL;
        TreeNode * t1_right = NULL;
        TreeNode * t2_right = NULL;
        
        if (t1 && t2) {
            t1_left = t1->left;
            t2_left = t2->left;
            t1_right = t1->right;
            t2_right = t2->right;
            n->val = t1->val + t2->val;
        } else if (t1) {
            t1_left = t1->left;
            t1_right = t1->right;
            n->val = t1->val;
        } else if (t2) {
            t2_left = t2->left;
            t2_right = t2->right;
            n->val = t2->val;
        }
        
        n->left = mergeTrees(t1_left, t2_left);
        n->right = mergeTrees(t1_right, t2_right);
        return n;
    }
};