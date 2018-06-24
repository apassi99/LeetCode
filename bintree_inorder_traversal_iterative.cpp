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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        list<TreeNode *> l;
        TreeNode * cur = root;
        
        while (cur) {
            l.push_back(cur);
            cur = cur->left;
        }
        
        while (!l.empty()) {
            cur = l.back();
            l.pop_back();
            result.push_back(cur->val);
            
            if (cur->right) {
                cur = cur->right;
                while (cur) {
                    l.push_back(cur);
                    cur = cur->left;
                }
            }
        }
        
        return result;
    }
};