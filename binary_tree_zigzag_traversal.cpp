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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> l;
        
        if (!root)
            return l;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        
        while ( !q.empty() ) {
            
            int size = q.size();
            list<int> mylist;
            
            for (int i = 0; i < size; i++) {
                TreeNode * n = q.front();
                q.pop();
                
                if (flag) mylist.push_back(n->val);
                else mylist.push_front(n->val);
                
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                
            }
            
            vector<int> v { std::begin(mylist), std::end(mylist) };
            
            flag = !flag;
            l.push_back(v);
        }
        
        return l;
    }
};
