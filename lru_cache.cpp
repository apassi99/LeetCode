class LRUCache {
public:
    LRUCache(int capacity) {
        
        assert(capacity >= 1);

        m_Size = 0;
        m_Capacity = capacity;
        
        m_Head = node_init(-1,-1,NULL, NULL);
        m_Tail = node_init(-1,-1,NULL, NULL);
        m_Head->next = m_Tail;
        m_Tail->prev = m_Head;
    }
    
    int get(int key) {

        int value = -1;

        if (m_Cache.find(key) != m_Cache.end()) {
            value = m_Cache[key]->value;
            remove_node(m_Cache[key]);
            insert_first(m_Cache[key]);
        }

        return value;
    }
    
    void put(int key, int value) {
        
        struct node * n = NULL;

        if (m_Cache.find(key) != m_Cache.end()) {
            n = m_Cache[key];
            n->value = value;
            remove_node(n);
        } else {
            n = node_init(value, key,NULL, NULL);
        }
        
        insert_first(n);

    }
    
private:
    
    /* Struct to define the list node. */
    struct node {
        int value;
        int key;
        struct node * prev;
        struct node * next;
    };
    
    /* Reference to the head and tail pointers */
    struct node * m_Head;
    struct node * m_Tail;
    
    /* Reference to the capacity of the cache */
    int m_Capacity;
    
    /* Reference to the current size of the cache */
    int m_Size;
    
    /* Reference to the map storing key,node pairs. */
    unordered_map<int, struct node *> m_Cache;
    
    /* Constructs a node object. */
    struct node * node_init(int value, int key, struct node *prev, struct node *next) {
        struct node *new_node = new struct node;
        new_node->value = value;
        new_node->key = key;
        new_node->prev = prev;
        new_node->next = next;
        return new_node;
    }
    
    /* Method to add node at the begining of the list*/
    void insert_first(struct node * n) {

        n->next = m_Head->next;
        m_Head->next->prev = n;
        m_Head->next = n;
        n->prev = m_Head;
        
        m_Size++;
        m_Cache[n->key] = n;
        
        if (m_Size > m_Capacity) {
            struct node * last_elem = m_Tail->prev;
            remove_node(last_elem);
            m_Cache.erase(last_elem->key);
            delete last_elem;
        }
    }
    
    void remove_node(struct node * n) {
        
        struct node * n_prev = n->prev;
        struct node * n_next = n->next;
        
        n_prev->next = n_next;
        n_next->prev = n_prev;
        
        m_Size--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */