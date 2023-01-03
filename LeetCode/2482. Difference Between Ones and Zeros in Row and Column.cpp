// Author: @AdarshGaur

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> onesRow(n, 0), onesCol(m, 0), zerosRow(n, 0), zerosCol(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                onesRow[i] += (grid[i][j] == 1);
                zerosRow[i] += (grid[i][j] == 0);
            }
        }
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                onesCol[j] += (grid[i][j] == 1);
                zerosCol[j] += (grid[i][j] == 0);
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
    }
};
