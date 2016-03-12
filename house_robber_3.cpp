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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
            
        map<TreeNode *, int> m;
        robHelper(root, &m);
        return m[root];
    }
    
private:

    void robHelper(TreeNode * n, map<TreeNode *, int> * m) {
        if (!n) {
            return;
        }
        
        if (!n->left && !n->right) {
            (*m)[n] = n->val;
            return;
        }
        
        robHelper(n->left, m);
        robHelper(n->right, m);
        
        int leftVal = (n->left) ? (*m)[n->left] : 0;
        int rightVal = (n->right) ? (*m)[n->right] : 0;
        
        int ll = (n->left) ? (n->left->left) ? (*m)[n->left->left] : 0 : 0;
        int lr = (n->left) ? (n->left->right) ? (*m)[n->left->right] : 0 : 0;
        int rl = (n->right) ? (n->right->left) ? (*m)[n->right->left] : 0 : 0;
        int rr = (n->right) ? (n->right->right) ? (*m)[n->right->right] : 0 : 0;
        
        
        int max1 = max(leftVal + rightVal, n->val);
        
        (*m)[n] = max(max1, ll + lr + rl + rr + n->val);
        
        cout << leftVal << "  " << rightVal << "  " << (*m)[n] << endl;
    }
};
