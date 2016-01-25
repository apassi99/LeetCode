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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> list;
        rightSideViewHelper(root, &list, 0);
        return list;
    }
    
    void rightSideViewHelper(TreeNode * n, vector<int> * list, int level) {
        
        if (!n)
            return;
        
        if ( level >= list->size()) {
            list->push_back(n->val);
        } else {
            (*list)[level] = n->val;
        }
        
        rightSideViewHelper(n->left, list, level+1);
        rightSideViewHelper(n->right, list, level+1);
        
    }
};
