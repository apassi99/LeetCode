#include <list>

using std::list;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        list<TreeLinkNode *> q;
        
        if (!root) return;
        
        root->next = NULL;
        if (root->left) q.push_back(root->left);
        if (root->right) q.push_back(root->right);
        
        while (q.size() > 0) {
            int len = q.size();
            
            for (int i = 0; i < len; i++) {
                TreeLinkNode * n = q.front();
                q.pop_front();
                if (n) n->next = (i < len-1) ? q.front() : NULL;
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
        }
    }
};
