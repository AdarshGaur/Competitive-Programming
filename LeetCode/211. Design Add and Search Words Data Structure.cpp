// Author : @AdarshGaur

struct TrieNode{
    TrieNode *child[26];
    bool isWord = false;
    TrieNode(){
        memset(child, NULL, sizeof(child));
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *p = root;
        for(auto& c: word){
            int index = c - 'a';
            if(p->child[index] == NULL)
                p->child[index] = new TrieNode();
            p = p->child[index];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return search(word, root);
    }
    
    bool search(string w, TrieNode* p){
        for(int c=0; c<w.size(); c++){
            if(w[c] == '.'){
                for(int i=0; i<26; i++){
                    if(p->child[i] and search(w.substr(c+1), p->child[i]))
                        return true;
                }
                return false;
            }else{
                int index = w[c] - 'a';
                if(!p or p->child[index] == NULL) return false;
                p = p->child[index];
            }
        }
        return p->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
