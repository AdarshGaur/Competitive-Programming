// Author : @AdarshGaur

class Solution {
public:
    typedef tuple<int,int,int> item;
    int d[5] = {1, 0, -1, 0, 1};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m, {-1, -1}));
        queue<item> q;
        q.push({0,0,k});
        dp[0][0] = {0, k};
        int moves = 0;
        bool found = false;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [x, y, kleft] = q.front();
                q.pop();
                if(x == n-1 and y == m-1){
                    found = true;
                    break;
                }
                for(int j = 0; j<4; j++){
                    int xp = x + d[j], yp = y + d[j+1];
                    if(xp < 0 or xp == n or yp < 0 or yp == m) continue;
                    if(dp[xp][yp].first == -1 or dp[xp][yp].second < kleft){
                        if(grid[xp][yp] == 1){
                            if(kleft > 0){
                                dp[xp][yp] = {moves+1, kleft-1};
                                q.push({xp, yp, kleft-1});
                            }
                        }else{
                            dp[xp][yp] = {moves+1, kleft};
                            q.push({xp, yp, kleft});
                        }
                    }
                }
            }
            if(!found) moves++;
            else break;
        }
        if(!found) moves = -1;
        return moves;
    }
};
