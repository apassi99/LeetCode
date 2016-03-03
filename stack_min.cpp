class MinStack {
public:
    void push(int x) {
        if (!top_node) {
            top_node = node_init(x, NULL);
            top_min = node_init(x, NULL);
            return;
        }
        
        top_node = node_init(x, top_node);
        
        if (top_node->val < top_min->val) {
            top_min = node_init(top_node->val, top_min);
        } else {
            top_min = node_init(top_min->val, top_min);
        }
    }

    void pop() {
        
        if (!top_node) {
            return;
        }
        
        struct node * temp = top_node;
        struct node * temp_min = top_min;
        
        top_node = top_node->next;
        top_min = top_min->next;
        
        delete temp;
        delete temp_min;
    }

    int top() {
        if (!top_node) {
            return -1;
        }
        
        return top_node->val;
    }

    int getMin() {
        if (!top_min) {
            return -1;
        }
        
        return top_min->val;
    }
    
private:

    struct node {
        struct node * next;
        int val;
    };
    
    struct node * node_init(int val, struct node * next) {
        struct node * n = new struct node;
        n->val = val;
        n->next = next;
        return n;
    }
    
    struct node * top_node = NULL;
    struct node * top_min = NULL;
};
