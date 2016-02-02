// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.
// For example,
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode* root) {
        
        vector<int> list;
        
        sumNumbersHelper(root, &list, 0);
        
        int sum = 0;
        
        for (int i = 0; i < list.size(); i++) {
            sum += list[i];
        }
        
        return sum;
    }
    
    void sumNumbersHelper(TreeNode* root, vector<int> * list, int sum) {
        if (!root) {
            return;
        }
        
        sum = (sum * 10) + root->val;
        
        if (!root->left && !root->right) {
            list->push_back(sum);
        }
        
        sumNumbersHelper(root->left, list, sum);
        sumNumbersHelper(root->right, list, sum);
    }
};
