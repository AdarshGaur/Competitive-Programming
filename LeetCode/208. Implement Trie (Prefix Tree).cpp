// Author : @AdarshGaur

class TrieNode{
public:
    TrieNode *next[26];
    bool isWord = false;
    TrieNode(){
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(auto i: word){
            int index = i - 'a';
            if(p->next[index] == NULL){
                p->next[index] = new TrieNode();
            }
            p = p->next[index];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for(auto i: word){
            int index = i - 'a';
            if(p->next[index] == NULL) return false;
            p = p->next[index];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(auto i: prefix){
            int index = i - 'a';
            if(p->next[index] == NULL) return false;
            p = p->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
