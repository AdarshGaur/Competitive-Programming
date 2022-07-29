// Author : @AdarshGaur

class Solution {
public:
    
    bool check(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[row][i] == c)
                return false;
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == c)
                return false;
        }
        for(int i=0, x = row/3 *3; i<3; i++, x++){
            for(int j=0, y = col/3 *3; j<3; j++, y++){
                if(board[x][y] == c)
                    return false;
            }
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true;
        if(j == 9) return backtrack(board, i+1, 0);
        
        if(board[i][j] != '.')
            return backtrack(board, i, j+1);
        
        for(auto c = '1'; c<='9'; c++){
            if(check(board, i, j, c)){
                board[i][j] = c;
                if(backtrack(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
