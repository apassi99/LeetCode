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
        int sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
    
private:
    
    void convertBSTHelper(TreeNode * n, int &sum) {
        if (!n) {
            return;
        }
        
        convertBSTHelper(n->right, sum);
        sum = n->val + sum;
        n->val = sum;
        convertBSTHelper(n->left, sum);
    }
};