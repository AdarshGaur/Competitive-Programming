// Author : @AdarshGaur

class Solution {
public:
    int empty=1, ans=0;
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y] == -1)
            return;
        if(grid[x][y] == 2){
            if(empty == 0) ans++;
            return;
        }
        grid[x][y] = -1;
        empty--;
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
        empty++;
        grid[x][y] = 1;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1) x=i, y=j;
            }
        }
        dfs(grid, x, y);
        return ans;
    }
};
