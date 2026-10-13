class Solution {
    int chessBoardLength;
    List<List<String>> nQueens = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        chessBoardLength = n;
        char[][] chessBoard = new char[n][n];
        for(int i=0; i<n; i++){
            Arrays.fill(chessBoard[i], '.');
        }

        nQueens.clear();
        int curRow = 0;
        backtrack(chessBoard, curRow);
        return nQueens;
    }

    public void backtrack(char[][] chessBoard, int curRow){
        if(curRow == chessBoardLength){
            addChessBoard(chessBoard);
            return;
        }

        for(int j=0; j<chessBoardLength; j++){
            chessBoard[curRow][j] = 'Q';

            if(isValidChessBoard(chessBoard, curRow, j)){
                backtrack(chessBoard, curRow+1);
            }
            chessBoard[curRow][j] = '.';
        }
        return;
    }

    public void addChessBoard(char[][] chessBoard){
        List<String> res = new ArrayList<>();
        for(char[] c: chessBoard){
            res.add(new String(c));
        }
        nQueens.add(res);
        return;
    }

    public boolean isValidChessBoard(char[][] chessBoard, int row, int col){
        // row will always have a single queen.
        // column
        for(int i=0; i<chessBoardLength; i++){
            if(i == row)
                continue;
            if(chessBoard[i][col] == 'Q'){
                return false;
            }
        }

        // diagonals
        for(int i=1; i<10; i++){
            // top-left direction
            int r = row - i;
            int c = col - i;
            if(badPosition(chessBoard, r, c)){
                return false;
            }

            // top-right direction
            r = row - i;
            c = col + i;
            if(badPosition(chessBoard, r, c)){
                return false;
            }
        }
        return true;
    }

    public boolean badPosition(char[][] chessBoard, int r, int c){
        if(r >= 0 && c >= 0 && r < chessBoardLength && c < chessBoardLength && chessBoard[r][c] == 'Q')
            return true;
        return false;
    }
}
