// Author : @AdarshGaur

struct TrieNode{
    TrieNode* child[26] = {};
    string* word;
    
    void insert(string& w){
        TrieNode* cur = this;
        for(auto &c: w){
            int index = c - 'a';
            if(cur->child[index] == NULL) cur->child[index] = new TrieNode();
            cur = cur->child[index];
        }
        cur->word = &w;
    }
};

class Solution {
public:
    int n, m;
    vector<string> ans;
    int d[5] = {0, 1, 0, -1, 0};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode T;
        for(auto& w: words){
            T.insert(w);
        }
        
        n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                dfs(board, i, j, &T);
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur){
        if(r<0 or r==n or c<0 or c==m or board[r][c]=='-' or cur->child[board[r][c]-'a']==NULL) return;
        char v = board[r][c];
        cur = cur->child[v-'a'];
        if(cur->word != NULL){
            ans.push_back(*(cur->word));
            cur->word = NULL;
        }
        board[r][c] = '-';
        for(int i=0; i<4; i++){
            dfs(board, r+d[i], c+d[i+1], cur);
        }
        board[r][c] = v;
    }
};
