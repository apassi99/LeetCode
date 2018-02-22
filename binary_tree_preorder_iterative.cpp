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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        
        if (!root) {
            return result;
        }
        
        list<TreeNode *> stack;
        stack.push_back(root);
        
        while (!stack.empty()) {
            
            TreeNode * n = stack.back();
            stack.pop_back();
            
            result.push_back(n->val);
            
            if (n->right) {
                stack.push_back(n->right);
            }
            
            if (n->left) {
                stack.push_back(n->left);
            }
        }

        return result;
    }
};