class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        m_Root = node_init();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        trie_node * cur = m_Root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL) {
                cur->children[word[i]-'a'] = node_init();
            }
            cur = cur->children[word[i]-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        trie_node * cur = m_Root;
        for (int i = 0; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->children[word[i]-'a'];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        trie_node * cur = m_Root;
        
        for (int i = 0; i < prefix.size(); i++) {
            if (cur->children[prefix[i]-'a'] == NULL)  {
                return false;
            }
            cur = cur->children[prefix[i]-'a'];
        }
        
        for (int i = 0; i < 26; i++) {
            if (cur->children[i] != NULL)
                return true;
        }

        return cur->isEnd;
    }

private:
    
    typedef struct trie_node {
        trie_node * children[26];
        bool isEnd;
    } trie_node;
    
    trie_node * m_Root;
    
    trie_node * node_init() {
        trie_node * n = new trie_node;
        for (int i = 0; i < 26; i++) {
            n->children[i] = NULL;
        }
        n->isEnd = false;
        return n;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */