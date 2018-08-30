/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node * lastNode;
        flattenHelper(head, lastNode);
        return head;
    }
    
private:
    
    void flattenHelper(Node * head, Node * &last) {
        
        Node * cur = head;
        
        while (cur) {
            
            last = cur;
            
            if (cur->child) {
                Node * tempLast;
                flattenHelper(cur->child, tempLast);
                
                Node * oldNext = cur->next;
                Node * child = cur->child;
                
                cur->child = NULL;
                
                cur->next = child;
                child->prev = cur;
                
                if (oldNext) {
                    tempLast->next = oldNext;
                    oldNext->prev = tempLast;
                }
                
                cur = oldNext;
                
            } else {
                cur = cur->next;
            }
        }
        
    }
};
