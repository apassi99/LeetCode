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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        vector<int> result;
        unordered_map<TreeNode *, TreeNode *> nodeToParentMap;
        set<TreeNode *> visitedNodes;
        
        buildNodeToParentMap(root, NULL, nodeToParentMap);
        distanceKHelper(target, K, result, nodeToParentMap, visitedNodes);
        
        return result;
    }
    
private:

    void buildNodeToParentMap(TreeNode * n, TreeNode * parent, 
                              unordered_map<TreeNode *, TreeNode *> &nodeToParentMap) {
        
        if (!n)
            return;
        
        if (parent) {
            nodeToParentMap[n] = parent;
        }
        
        buildNodeToParentMap(n->left, n, nodeToParentMap);
        buildNodeToParentMap(n->right, n, nodeToParentMap);
    }
    
    void distanceKHelper(TreeNode * root, int k, vector<int> &result, 
                         unordered_map<TreeNode *, TreeNode *> &nodeToParentMap,
                         set<TreeNode *> &visitedNodes) {
        
        if (!root || k < 0)
            return;
        
        if (visitedNodes.find(root) != visitedNodes.end()) {
            return;
        }
        
        if (k == 0) {
            result.push_back(root->val);
            return;
        }
        
        visitedNodes.insert(root);
        
        distanceKHelper(root->left, k-1, result, nodeToParentMap, visitedNodes);
        distanceKHelper(root->right, k-1, result, nodeToParentMap, visitedNodes);
        
        if (nodeToParentMap.find(root) != nodeToParentMap.end()) {
            distanceKHelper(nodeToParentMap[root], k-1, result, nodeToParentMap, visitedNodes);
        }
    }
    
    
};