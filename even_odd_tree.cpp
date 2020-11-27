/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        
        list<TreeNode *> q;
        
        if (root)
            q.push_back(root);
        
        int index = 0;
        
        
        while (!q.empty())
        {
            int size = q.size();
            
            TreeNode * prevNode = NULL;
            
            for (int i = 0; i < size; i++)
            {
                TreeNode * n = q.front();
                q.pop_front();
                
                if (n->left)
                    q.push_back(n->left);
                if (n->right)
                    q.push_back(n->right);
                
                if (index % 2 == 0)
                {
                    // At even-indexed level
                    if (n->val % 2 == 0)
                        return false;
                    if (prevNode && n->val <= prevNode->val)
                        return false;
                }
                else
                {
                    // At odd-indexed level
                    if (n->val % 2 != 0)
                        return false;
                    if (prevNode && n->val >= prevNode->val)
                        return false;
                }
                
                prevNode = n;
            }
            
            index++;
        }
        
        return true;
    }
};