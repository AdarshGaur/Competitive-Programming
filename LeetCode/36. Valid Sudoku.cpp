// Author : @AdarshGaur

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]{}, col[9][9]{}, box[9][9]{};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == '.') continue;
                int k = i/3 *3 + j/3;
                int n = board[i][j] - '0' -1;
                if(row[i][n] or col[j][n] or box[k][n])
                    return false;
                row[i][n] = col[j][n] = box[k][n] = 1;
            }
        }
        return true;
    }
};
