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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        
        if (postorder.empty() || inorder.empty()) {
            return NULL;
        }
        
        // Intialize the index map
        map<int, int> * inoderIndexMap = new map<int, int>();
        
        // Build the index map
        for (int i = 0; i < inorder.size(); i++) {
            (*inoderIndexMap)[inorder[i]] = i;
        }
        
        // Initialze queue
        list<TreeNode *> *q = new list<TreeNode *>();
        
        // Initialize root
        TreeNode * root = new TreeNode(postorder[postorder.size()-1]);
        q->push_back(root);
        
        for (int i = postorder.size()-2; i >= 0; i--) {
            
            TreeNode * newNode = new TreeNode(postorder[i]);    
            
            while (true) {
                
                TreeNode * n = q->back();
                if ((*inoderIndexMap)[n->val] < (*inoderIndexMap)[postorder[i]]) {
                    n->right = newNode;
                    q->push_back(newNode);
                    break;
                } else {
                    
                    if (q->size() > 1) {
                        q->pop_back();
                    }

                    TreeNode * temp = q->back();
                
                    if ((*inoderIndexMap)[temp->val] < (*inoderIndexMap)[postorder[i]]) {
                        
                        
                        // Edge case when the node belongs 
                        // to the furthermost left child
                        while (n->left) {
                            n = n->left;
                        }
                        
                        n->left = newNode;
                        q->push_back(n);
                        q->push_back(newNode);
                        break;
                    } else if (q->size() == 1) {
                        temp->left = newNode;
                        q->pop_back();
                        q->push_back(newNode);
                        break;
                    }
                }
            }
        }
        
        // Deallocate memory for index map and queue.-
        delete inoderIndexMap;
        delete q;
        
        return root;
    }
};