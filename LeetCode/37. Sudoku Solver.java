class Solution {
    int boardLength = 9;
    int boardWidth = 9;

    public void solveSudoku(char[][] board) {
        backtrack(board, nextEmptyCell(board));
        return;
    }

    public boolean backtrack(char[][] board, List<Integer> curPosition){
        if(curPosition.get(0) == -1){
            return true;
        }
        // find the possible value at position
            // check in the row
            // check in the col
            // check in the sub-grid
        int[] possibleValues = {0,1,2,3,4,5,6,7,8,9};
        int curRow = curPosition.get(0);
        int curCol = curPosition.get(1);
        for(int i=0; i<boardLength; i++){
            if(board[i][curCol] != '.'){
                int idx = Character.getNumericValue(board[i][curCol]);
                possibleValues[idx] = -1;
            }
        }
        for(int j=0; j<boardWidth; j++){
            if(board[curRow][j] != '.'){
                possibleValues[board[curRow][j] - '0'] = -1;
            }
        }

        // find the range of row and col for that sub-grid
        int sRow = (int)(curRow/3) * 3 ;
        int tRow = sRow + 2;
        int sCol = (int)(curCol/3) * 3;
        int tCol = sCol + 2;
        for(int i=sRow; i<=tRow; i++){
            for(int j=sCol; j<=tCol; j++){
                if(board[i][j] != '.'){
                    possibleValues[board[i][j] - '0'] = -1;
                }
            }
        }
        
        // iterate over the possible values that can be filled
        // at current position and backtrack
        for(int i=1; i<=boardLength; i++){
            if(possibleValues[i] == -1)
                continue;
            board[curRow][curCol] = (char)(i + '0');
            if(backtrack(board, nextEmptyCell(board))){
                return true;
            }
            board[curRow][curCol] = '.';
        }
        return false;
    }

    public List<Integer> nextEmptyCell(char[][] board){
        for(int i=0; i<boardLength; i++){
            for(int j=0; j<boardWidth; j++){
                if(board[i][j] == '.'){
                    return List.of(i,j);
                }
            }
        }
        return List.of(-1,-1);
    }
}
