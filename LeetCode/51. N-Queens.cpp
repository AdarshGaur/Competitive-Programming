// Author : @AdarshGaur
class Solution {
public:
    vector<vector<string>> ans;
    
    void backTrack(vector<string>& board, int row, int& n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(isValid(board, row, col, n)){
                board[row][col] = 'Q';
                backTrack(board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& board, int row, int col, int& n){
        // for the column
        for(int r=0; r<n; r++){
            if(r == row) continue;
            if(board[r][col] == 'Q')
                return false;
        }
        // for the diagonals
        int d = min(row, col);
        int r = row - d, c = col - d;
        for(; r<n and c<n; r++, c++){
            if(r == row) continue;
            if(board[r][c] == 'Q')
                return false;
        }
        d = min(row, n-col-1);
        r = row - d, c = col + d;
        for(; r<n and c>=0; r++, c--){
            if(r == row) continue;
            if(board[r][c] == 'Q')
                return false;
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0, n);
        return ans;
    }
};
