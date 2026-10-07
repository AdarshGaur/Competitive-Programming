class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int lower = 0, upper = n-1;
        while(lower < upper){
            // iterate over the row
            for(int j=lower; j<upper; j++){
                // 4 swap operations
                int temp = matrix[lower][j];
                matrix[lower][j] = matrix[upper -j + lower][lower];
                matrix[upper -j + lower][lower] = matrix[upper][upper -j + lower];
                matrix[upper][upper -j + lower] = matrix[j][upper];
                matrix[j][upper] = temp;
            }
            lower++;
            upper--;
        }
        return;
    }
}
