class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        m_Root = node_init();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); i++) {
            addWord(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        
        trie_node * cur = m_Root;
        
        for (int i = 0; i < word.size(); i++) {
            for (int j = 0; j < 26; j++) {    
                if (cur->children[j] != NULL && word[i]-'a' != j) {
                    if (searchHelper(word, i+1, cur->children[j])) {
                        return true;
                    }
                }
            }
            
            if (cur->children[word[i]-'a'] == NULL) {
                return false;
            }

            cur = cur->children[word[i]-'a'];
        }
        
        return false;
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
    
    void addWord(const string &str) {
        
        trie_node * cur = m_Root;
        for (int i = 0; i < str.size(); i++) {
            if (cur->children[str[i]-'a'] == NULL) {
                cur->children[str[i]-'a'] = node_init();
            }
            cur = cur->children[str[i]-'a'];
        }
        cur->isEnd = true;
    }
    
    bool searchHelper(string &word, int idx, trie_node * n) {
        
        trie_node * cur = n;
        for (int i = idx; i < word.size(); i++) {
            if (cur->children[word[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->children[word[i]-'a'];
        }
        return cur->isEnd == true;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */