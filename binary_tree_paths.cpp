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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str = "";
        binaryTreePathsHelper(root, result, str);
        return result;
    }
    
private:
    
    void binaryTreePathsHelper(TreeNode *n, vector<string> &result, string &str) {
        
        if (!n)
            return;
        
        if (!n->left && !n->right) {
            if (str.size() > 0)
                result.push_back(str + "->" + to_string(n->val));
            else
                result.push_back(to_string(n->val));
            return;
        }
        
        string cur = (str.empty()) ? to_string(n->val) : str + "->" + to_string(n->val);
        
        binaryTreePathsHelper(n->left, result, cur);
        binaryTreePathsHelper(n->right, result, cur);
    }
};