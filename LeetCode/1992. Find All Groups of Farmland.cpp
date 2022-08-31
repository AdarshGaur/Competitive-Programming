// Author : @AdarshGaur

class Solution {
public:
    vector<vector<bool>> vis;
    int d[5] = {1, 0, 1};
    int lr, lc, hr, hc, n, m;
    
    void dfs(vector<vector<int>>& land, int i, int j){
        lr = min(lr, i), hr = max(hr, i);
        lc = min(lc, j), hc = max(hc, j);
        vis[i][j] = true;
        for(int k=0; k<3; k++){
            int x = i + d[k], y = j + d[k+1];
            if(x<n and y<m and land[x][y] == 1 and !vis[x][y])
                dfs(land, x, y);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vis.resize(n, vector<bool>(m ,false));
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 and !vis[i][j]){
                    lr=i, hr=i, lc=j, hc=j;
                    dfs(land, i, j);
                    ans.push_back({lr, lc, hr, hc});
                }
            }
        }
        return ans;
    }
};
