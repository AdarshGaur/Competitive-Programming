class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int n = matrix.length, m = matrix[0].length;
        int sRow = 0, eRow = n-1, sCol = 0, eCol = m-1;
        while(sRow <= eRow && sCol <= eCol){
            // first row
            for(int j=sCol; j<=eCol; j++){
                res.add(matrix[sRow][j]);
            }
            sRow++;

            // last col
            for(int i=sRow; i<=eRow; i++){
                res.add(matrix[i][eCol]);
            }
            eCol--;

            if(sRow <= eRow){
                // last row
                for(int j=eCol; j>=sCol; j--){
                    res.add(matrix[eRow][j]);
                }
                eRow--;
            }

            if(sCol <= eCol){
                // first col
                for(int i=eRow; i>=sRow; i--){
                    res.add(matrix[i][sCol]);
                }
                sCol++;
            }
        }
        return res;
    }
}
