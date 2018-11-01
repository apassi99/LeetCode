/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorder_helper(root, result);
        return result;
    }
    
private:
    
    void preorder_helper(Node * n, vector<int> &result) {
        
        if (!n)
            return;
        
        result.push_back(n->val);
        
        for (int i = 0; i < n->children.size(); i++) {
            preorder_helper(n->children[i], result);
        }
        
    }
};