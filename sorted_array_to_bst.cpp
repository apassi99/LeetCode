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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode * root = NULL;
        sortedArrayToBSTHelper(nums, &root, 0, nums.size() - 1);
        return root;
    }
    
private:

    void sortedArrayToBSTHelper(vector<int>& nums, TreeNode ** root, int l, int h) {

        if (l > h) {
            return;
        }
        
        if (l == h) {
            *root = insert(*root, nums[l]);
            return;
        }
        
        int mid = (l + h) / 2;
        *root = insert(*root, nums[mid]);
        
        sortedArrayToBSTHelper(nums, root, l, mid-1);
        sortedArrayToBSTHelper(nums, root, mid+1, h);
    }

    TreeNode * insert(TreeNode * root, int val) {
        if (!root) {
            return node_init(val, NULL, NULL);
        }
        
        if (root->val == val) {
            return root;
        }
        
        if (val > root->val) {
            root->right = insert(root->right, val);
        } else {
            root->left = insert(root->left, val);
        }
        
        return root;
    }
    
    TreeNode * node_init(int val, TreeNode * l, TreeNode * r) {
        TreeNode * n = new TreeNode(val);
        n->left = l;
        n->right = r;
        return n;
    }
};
