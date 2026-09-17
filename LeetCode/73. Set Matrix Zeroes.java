class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> rowsToZero = new ArrayList<>();
        List<Integer> colsToZero = new ArrayList<>();
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    rowsToZero.add(i);
                    colsToZero.add(j);
                }
            }
        }

        for(int i = 0; i < rowsToZero.size(); i++){
            if(i > 0 && rowsToZero.get(i) == rowsToZero.get(i-1)){
                continue;
            }
            int k = rowsToZero.get(i);
            for(int j = 0; j < matrix[0].length; j++){
                matrix[k][j] = 0;
            }
        }

        for(int j = 0; j < colsToZero.size(); j++){
            if(j > 0 && colsToZero.get(j) == colsToZero.get(j-1)){
                continue;
            }
            int k = colsToZero.get(j);
            for(int i = 0; i < matrix.length; i++){
                matrix[i][k] = 0;
            }
        }

        return;
    }
}

