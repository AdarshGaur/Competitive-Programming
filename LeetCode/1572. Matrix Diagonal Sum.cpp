// Author: @AdarshGaur

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size(); i++){
            sum += mat[i][i];
            if(i != mat[i].size() - i -1)
                sum += mat[i][mat[i].size() - i -1];
        }
        return sum;
    }
};

