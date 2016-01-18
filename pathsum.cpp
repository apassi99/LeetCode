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
    bool hasPathSum(TreeNode* root, int sum) {
        
        return hasPath(root, sum, 0);
    }
    
    bool hasPath(TreeNode * n, int sum, int sumSoFar) {
        if (!n)
            return false;
            
        sumSoFar += n->val;
        
        if (sumSoFar == sum && isLeaf(n))
            return true;
            
        return hasPath(n->left, sum, sumSoFar) ||  hasPath(n->right, sum, sumSoFar);
    }
    
    bool isLeaf(TreeNode * n) {
        if (!n)
            return false;
        
        return !n->left && !n->right;
    }
};
