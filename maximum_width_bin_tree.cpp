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
    int widthOfBinaryTree(TreeNode* root) {
        
        int result = 0;
        
        list<NodeInfo> q;
        
        if (root) {
            NodeInfo nodeinfo = getNodeInfo(root, 0);
            q.push_back(nodeinfo);
        }
        
        while (!q.empty()) {
            int size = q.size();
            int startIdx = INT_MAX;
            int lastIdx = INT_MIN;
            
            for (int i = 0; i < size; i++) {
                NodeInfo nodeInfo = q.front();
                TreeNode * n = nodeInfo.node;
                q.pop_front();
                
                if (n) {

                    startIdx = min(startIdx, nodeInfo.index);
                    lastIdx = max(lastIdx, nodeInfo.index);
                    
                    if (n->left) {
                        NodeInfo leftNodeInfo = getNodeInfo(n->left, nodeInfo.index * 2);
                        q.push_back(leftNodeInfo);
                    }
                    
                    if (n->right) {
                        NodeInfo rightNodeInfo = getNodeInfo(n->right, (nodeInfo.index * 2) + 1);
                        q.push_back(rightNodeInfo);
                    }
                }
            }
            
            if (startIdx != INT_MAX || lastIdx != INT_MIN)
                result = max(result, lastIdx - startIdx + 1);
            else {
                result = 1;
            }
        }
        
        return result;
    }
    
private:
    
    typedef struct {
        TreeNode * node;
        int index;
    } NodeInfo;
    
    NodeInfo getNodeInfo(TreeNode * node, int index) {
        NodeInfo info;
        info.node = node;
        info.index = index;
        return info;
    }
};