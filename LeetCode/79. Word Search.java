class Solution {
    int n, m;
    int[] directions = {0, -1, 0, 1, 0};

    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word.charAt(0)){
                    if(backtrackWord(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }

    public boolean backtrackWord(char[][] board, String word, int x, int y, int k){
        if(k == word.length() -1)
            return true;
        board[x][y] = '0';
        for(int i=0; i<4; i++){
            int xn = x + directions[i];
            int yn = y + directions[i+1];
            if(xn >= 0 && xn < m && yn >= 0 && yn < n){
                if(board[xn][yn] == word.charAt(k+1)){
                    if(backtrackWord(board, word, xn, yn, k+1))
                        return true;
                }
            }
        }
        board[x][y] = word.charAt(k);
        return false;
    }
}
