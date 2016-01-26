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
            
        list<TreeNode*> q;
        q.push_back(root);
        
        while ( !q.empty() ) {
            
            int size = q.size();
            
            vector<int> v;
            
            for (int i = 0; i < size; i++) {
                
                TreeNode * n = q.front();
                q.pop_front();
                
                v.push_back(n->val);
                
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            
            l.push_back(v);
            
        }
        
        return l;
    }
};
