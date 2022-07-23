// Author : @AdarshGaur

class Solution {
public:
    vector<int> ans;
    
    struct Trie{
        vector<Trie* > child;
        int data;
        Trie(){
            child = vector<Trie*>(10, NULL);
            data = -1;
        }
    };

    void add(Trie* root, int n){
        string s = to_string(n);
        for(auto &c: s){
            int index = c - '0';
            if(!root->child[index])
                root->child[index] = new Trie();
            root = root->child[index];
        }
        root->data = n;
    }

    void all(Trie* root){
        if(!root) return;
        if(root->data != -1)
            ans.push_back(root->data);
        for(int i=0; i<10; i++){
            if(root->child[i])
                all(root->child[i]);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        Trie* T = new Trie();
        for(int i=1; i<=n; i++)
            add(T, i);
        all(T);
        return ans;
    }
};
