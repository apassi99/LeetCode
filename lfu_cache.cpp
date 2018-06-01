class LFUCache {
public:
    LFUCache(int capacity) {

        m_Size = 0;
        m_Capacity = capacity;
        
        m_Head = bucket_init(0, NULL, NULL);
        m_Tail = bucket_init(0, NULL, NULL);
        m_Head->next = m_Tail;
        m_Tail->prev = m_Head;
    }
    
    int get(int key) {
        
        int value = -1;
        
        if (m_Capacity <= 0) {
            return value;
        }
        
        if (m_Cache.find(key) != m_Cache.end()) {
            value = m_Cache[key]->value;
            update_node(m_Cache[key]);
        }
        
        return value;
    }
    
    void put(int key, int value) {
        
        struct node * n = NULL;
        
        if (m_Capacity <= 0) {
            return;
        }
        
        if (m_Cache.find(key) != m_Cache.end()) {
            n = m_Cache[key];
            n->value = value;
        } else {
            n = node_init(value, key, 0, NULL, NULL);
            m_Size++;
        }
        
        update_node(n);
    }
    
private:
    
    /* Struct to define the list node. */
    struct node {
        int value;
        int key;
        int freq;
        struct node * prev;
        struct node * next;
    };
    
    struct bucket {
        int freq;
        struct node * m_Head;
        struct node * m_Tail;
        struct bucket * next;
        struct bucket * prev;
    };
    
    /* Reference to the head and tail pointers of the freq bucket list. */
    struct bucket * m_Head;
    struct bucket * m_Tail;
    
    /* Reference to the capacity of the cache */
    int m_Capacity;
    
    /* Reference to the current size of the cache */
    int m_Size;
    
    /* Reference to the map storing key,node pairs. */
    unordered_map<int, struct node *> m_Cache;
    
    /* Reference to the map storing freq,node pairs. */
    unordered_map<int, struct bucket *> m_FreqCache;
    
    /* Constructs a node object. */
    struct node * node_init(int value, int key, int freq,
                            struct node *prev, struct node *next) {

        struct node *new_node = new struct node;
        new_node->value = value;
        new_node->key = key;
        new_node->freq = freq;
        new_node->prev = prev;
        new_node->next = next;
        return new_node;
    }
    
    struct bucket * bucket_init(int freq, struct bucket *prev, struct bucket *next) {
        
        struct bucket *new_bucket = new struct bucket;
        new_bucket->m_Head = node_init(-1,-1, freq, NULL, NULL);
        new_bucket->m_Tail = node_init(-1,-1, freq, NULL, NULL);
        new_bucket->m_Head->next = new_bucket->m_Tail;
        new_bucket->m_Tail->prev = new_bucket->m_Head;
        new_bucket->prev = prev;
        new_bucket->next = next;
        new_bucket->freq = freq;
        return new_bucket;
    }
    
    void update_node(struct node * n) {

        int freq = n->freq;
        int newFreq = n->freq + 1;
        n->freq = newFreq;
        struct bucket * new_bucket = NULL;
    
        if (m_Size > m_Capacity) {
            struct bucket * lfu_bucket = m_Tail->prev;
            struct node * lru_node = lfu_bucket->m_Tail->prev;
            remove_node(lru_node);
            m_Cache.erase(lru_node->key);
            delete lru_node;
            m_Size--;

            if (lfu_bucket->m_Head->next == lfu_bucket->m_Tail) {
                remove_bucket(lfu_bucket);
            }
        }
        
        if (m_FreqCache.find(newFreq) != m_FreqCache.end()) {
            new_bucket = m_FreqCache[newFreq];
        } else {
            struct bucket * old_bucket = m_Tail;
            
            if (m_FreqCache.find(freq) != m_FreqCache.end()) {
                old_bucket = m_FreqCache[freq];
            }
            
            new_bucket = bucket_init(newFreq, NULL, NULL);
            
            new_bucket->next = old_bucket;
            new_bucket->prev = old_bucket->prev;
            old_bucket->prev->next = new_bucket;
            old_bucket->prev = new_bucket;
        }
        
        if (m_Cache.find(n->key) != m_Cache.end()) {
            struct bucket * old_bucket = m_FreqCache[freq];
            remove_node(n);
            
            if (old_bucket->m_Head->next == old_bucket->m_Tail) {
                remove_bucket(old_bucket);
            }
        }
        
        add_node_to_bucket(new_bucket, n);
        m_FreqCache[newFreq] = new_bucket;
        m_Cache[n->key] = n;
    }
    
    void add_node_to_bucket(struct bucket *b, struct node *n) {
        
        struct node * b_head = b->m_Head;
        
        n->next = b_head->next;
        n->prev = b_head;
        b_head->next->prev = n;
        b_head->next = n;
    }
    
    void remove_node(struct node * n) {

        struct node * n_prev = n->prev;
        struct node * n_next = n->next;
        
        n_prev->next = n_next;
        n_next->prev = n_prev;
    }

    void remove_bucket(struct bucket * b) {
        struct bucket * b_prev = b->prev;
        struct bucket * b_next = b->next;
        
        b_prev->next = b_next;
        b_next->prev = b_prev;
        m_FreqCache.erase(b->freq);
        
        delete b->m_Head;
        delete b->m_Tail;
        delete b;
    }
    
    void print_list() {
        struct bucket *cur = m_Head->next;
        cout << "{ ";
        while (cur != m_Tail) {
            struct node * cur_list = cur->m_Head->next;
            cout << "[ ";
            while (cur_list != cur->m_Tail) {
                cout << "(" << cur_list->key << "," << cur_list->value << "), ";
                cur_list = cur_list->next;
            }
            cout << " ]";
            cur = cur->next;
        }
        cout << " }" << endl << endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */