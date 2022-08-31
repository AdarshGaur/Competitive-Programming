// Author : @AdarshGaur

class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& leave, int i, int j, int& n, int& m){
        leave[i][j] = true;
        for(int k=0; k<4; k++){
            int x = i+d[k], y = j+d[k+1];
            if(x>=0 and x<n and y>=0 and y<m and board[x][y] == 'O' and !leave[x][y])
                dfs(board, leave, x, y, n, m);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> leave(n, vector<bool>(m, false));
        for(int i: {0, n-1}){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' and !leave[i][j])
                    dfs(board, leave, i, j, n, m);
            }
        }
        for(int j:{0, m-1}){
            for(int i=0; i<n; i++){
                if(board[i][j] == 'O' and !leave[i][j])
                    dfs(board, leave, i, j, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' and !leave[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
