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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        postOrderTraversalHelper(root, &list);
        return list;
    }
    
    void postOrderTraversalHelper(TreeNode * n, vector<int> * list) {
        if (!n)
            return;
        
        postOrderTraversalHelper(n->left, list);
        postOrderTraversalHelper(n->right, list);
        list->push_back(n->val);
    }
};
