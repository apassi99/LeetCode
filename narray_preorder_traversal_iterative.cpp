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
        list<Node *> nodes;
        
        if (root)
            nodes.push_back(root);
        
        while (!nodes.empty()) {
            
            Node * n = nodes.back();
            nodes.pop_back();
            
            for (int i = n->children.size() - 1; i >= 0; i--) {
                nodes.push_back(n->children[i]);
            }
            
            result.push_back(n->val);
        }
        
        
        return result;
    }
};