class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        int startRow = x;
        int endRow = x+k -1;
        while(startRow < endRow){
            for(int j=y; j<y+k; j++){
                int tempVal = grid[startRow][j];
                grid[startRow][j] = grid[endRow][j];
                grid[endRow][j] = tempVal;
            }
            startRow++;
            endRow--;
        }
        return grid;
    }
}

