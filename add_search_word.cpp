class WordDictionary {
public:
   /** Initialize your data structure here. */
   WordDictionary() {
      m_Root = create_trie_node();
   }
    
   /** Adds a word into the data structure. */
   void addWord(string word) {

      trie_node * n = m_Root;

      for (int i = 0; i < word.size(); i++) {
         int index = word[i] - 'a';
         if (n->nodes[index] == NULL) {
            n->nodes[index] = create_trie_node();
         }
         n = n->nodes[index];
      }
      n->isEnd = true;
   }
    
   /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
   bool search(string word) {
      return search(word, m_Root);
   }

private:

   struct trie_node {
      trie_node * nodes[26];
      bool isEnd;
   };
    
   bool search(string word, trie_node *n) {

      for (int i = 0; i < word.size(); i++) {

         if (word[i] == '.') {

            string temp = word.substr(i+1);

            for (int j = 0; j < 26; j++) {
               if (n->nodes[j] && search(temp, n->nodes[j])) {
                  return true;
               }
            }
            return false;
         } else {
            int index = word[i] - 'a';

            if (n->nodes[index]) {
               if (i == word.size() - 1) {
                  return n->nodes[index]->isEnd;
               }
               n = n->nodes[index];
            } else {
               return false;
            }
         }
      }
      return n->isEnd;
    }

   struct trie_node * create_trie_node() {
      trie_node * n = new trie_node;
      n->isEnd = false;
        
      for (int i = 0; i < 26; i++) {
         n->nodes[i] = NULL;
      }
      return n;
    }
    
   trie_node * m_Root;
    
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */