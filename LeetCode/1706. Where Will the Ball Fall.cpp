// Author : @AdarshGaur

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int j=0; j<n; j++){
            int col = j;
            for(int i=0; i<m; i++){
                int next = col + grid[i][col];
                if(next < 0 or next == n or grid[i][col] != grid[i][next]){
                    ans[j] = -1;
                    break;
                }
                ans[j] = next;
                col = next;
            }
        }
        return ans;
    }
};
