// Given a binary tree and a sum, find all root-to-leaf 
// paths where each path's sum equals the given sum.

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> list;
        vector<int> l;
        
        path_sum_helper(root, &list, l, sum, 0);
        
        return list;
    }

private:
    void path_sum_helper(TreeNode * n, vector<vector<int>> *list, 
                        vector<int> l, int target, int sum) {
        
        if (!n)
            return;
            
        sum += n->val;
        l.push_back(n->val);
        
        //Leaf node
        if (!n->left && !n->right && target == sum) {
            list->push_back(l);
        }
        
        path_sum_helper(n->left, list, l, target, sum);
        path_sum_helper(n->right, list, l, target, sum);
    }
};
