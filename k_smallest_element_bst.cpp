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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        kthSmallestHelper(root, k, &result);
        return result;
    }

private:
    
    void kthSmallestHelper(TreeNode *n, int &k, int *val) {
        
        if (!n || k < 0) {
            return;
        }
        
        kthSmallestHelper(n->left, k, val);
        k--;
        
        if (k == 0) {
            *val = n->val;
        }

        kthSmallestHelper(n->right, k, val);
        
    }
};