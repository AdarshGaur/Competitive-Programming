class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        for(int i=0; i<4; i++){
            mat = rotateBy90(mat);
            if(areSame(mat, target))
                return true;
        }
        return false;
    }

    public int[][] rotateBy90(int[][] mat){
        int n = mat.length;
        for(int i=0; i<n/2; i++){
            // take consideration of reduced columns as well
            for(int j=i; j<n-1 -i; j++){
                // 4 assign operations
                int x = mat[i][j];
                mat[i][j] = mat[n-1 -j][i];              // assigning top-left cornor
                mat[n-1 -j][i] = mat[n-1 -i][n-1 -j];    // assigning bottom-left corner
                mat[n-1 -i][n-1 -j] = mat[j][n-1 -i];   // assigning bottom-rigth corner
                mat[j][n-1 -i] = x;                     // assigning top-right corner
            }
        }
        return mat;
    }

    public boolean areSame(int[][] mat, int[][] target){
        for(int i=0; i<mat.length; i++){
            for(int j=0; j<mat[i].length; j++){
                if(mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
}

