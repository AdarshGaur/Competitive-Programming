// Author : @AdarshGaur

class Solution {
public:
    const int mod = 1e9 +7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int store[n][m][k];
        memset(store, 0, sizeof(store));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 and j == m-1){
                    int r = grid[i][j] % k;
                    store[i][j][r] = 1;
                    continue;
                }
                if(i != n-1){
                    for(int ik = 0; ik < k; ik++){
                        int r = (ik + grid[i][j]) %k;
                        store[i][j][r] += store[i+1][j][ik];
                        store[i][j][r] %= mod;
                    }
                }
                if(j != m-1){
                    for(int ik=0; ik<k; ik++){
                        int r = (ik+grid[i][j]) %k;
                        store[i][j][r] += store[i][j+1][ik];
                        store[i][j][r] %= mod;
                    }
                }
            }
        }
        return store[0][0][0];
    }
};
