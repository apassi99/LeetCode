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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if (!root) {
            return root;
        }
        
        if (d-1 == 1) {
            TreeNode * n1 = create_tree_node(v, root->left, NULL);
            TreeNode * n2 = create_tree_node(v, NULL, root->right);
            root->left = n1;
            root->right = n2;
            return root;
        } else if (d == 1) {
            TreeNode * n1 = create_tree_node(v, root, NULL);
            return n1;
        }
        
        root->left = addOneRow(root->left, v, d-1);
        root->right = addOneRow(root->right, v, d-1);
        return root;
        
    }
    
private:
    
    TreeNode * create_tree_node(int val, TreeNode *left, TreeNode *right) {
        TreeNode * n = (TreeNode *) malloc(sizeof(TreeNode));
        n->val = val;
        n->left = left;
        n->right = right;
        return n;
    }
};