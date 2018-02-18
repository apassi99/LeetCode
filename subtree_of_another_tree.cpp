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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSubtreeHelper(s, t, false);
    }
    
private:
    
    bool isSubtreeHelper(TreeNode* s, TreeNode* t, bool flag) {
        if (!s ^ !t) {
            return false;
        }
        
        if (!s && !t) {
            return true;
        }
        
        if (s->val == t->val) {
            if( isSubtreeHelper(s->left, t->left, true) &&
                isSubtreeHelper(s->right, t->right, true) ) {
                return true;
            }
        } else if (flag) {
            return false;
        }

        return isSubtreeHelper(s->left, t, false) || isSubtreeHelper(s->right, t, false);
    }
};