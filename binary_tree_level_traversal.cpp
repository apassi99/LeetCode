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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> l;
        
        if (!root)
            return l;
            
        levelOrder(root, &l, 0);
        
        return l;
    }
    
    void levelOrder(TreeNode* n, vector<vector<int>> * list, int level) {
        
        if (!n)
            return;
        
        if (level >= list->size()) {
            vector<int> l;
            l.push_back(n->val);
            list->push_back(l);
        } else {
            (*list)[level].push_back(n->val);
        }
        
        levelOrder(n->left, list, level+1);
        levelOrder(n->right, list, level+1);
        
    }
};
