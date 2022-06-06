// Author: @AdarshGaur

class Solution {
public:
    int ans = 0;
    
    void solve(vector<string>& board, int row, int& n){
        if(row == n){
            ans += 1;
            return;
        }
        for(int col=0; col<n; col++){
            if(isValid(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& board, int& row, int& col, int& n){
        // column
        int r = row-1, c = col;
        while(r>=0){
            if(board[r][c] == 'Q')
                return false;
            r--;
        }
        // diagonals
        r = row-1, c = col-1;
        while(r>=0 & c>=0){
            if(board[r][c] == 'Q')
                return false;
            r--, c--;
        }
        r = row -1, c = col+1;
        while(r>=0 & c<n){
            if(board[r][c] == 'Q')
                return false;
            r--, c++;
        }
        return true;
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};
