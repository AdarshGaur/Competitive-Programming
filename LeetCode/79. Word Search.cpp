// Author : @AdarshGaur

class Solution {
public:
    vector<vector<bool>> vis;
    int n, m;
    pair<int,int> dx[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool dfs(int& x, int& y, vector<vector<char>>& b, string& w, int indx){
        if(indx == w.size()) return true;
        for(auto &[i, j]: dx){
            int nx = x+i, ny = y+j;
            if(nx >=0 and nx < n and ny >= 0 and ny < m and b[nx][ny] == w[indx] and !vis[nx][ny]){
                vis[nx][ny] = true;
                if( dfs(nx, ny, b, w, indx+1) ) return true;
                vis[nx][ny] = false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    if(dfs(i, j, board, word, 1))
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};
