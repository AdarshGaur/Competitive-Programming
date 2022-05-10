// Author : @AdarshGaur

class Solution {
public:
    const int INF = 1e9;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    bool Predicate(vector<vector<int>>& fireSpread, int delay, vector<vector<int>>& grid){
        //// function to check if person can move to the final position
        //// by having a delay in starting time by using bfs or dfs
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INF));
        dis[0][0] = delay;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int u = p.first, v = p.second;
            for(int i=0; i<4; i++){
                int x = u + dx[i], y = v + dy[i];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0 && dis[x][y] > dis[u][v]+1){
                    int extra = 0; // for the corner case of safehouse
                    if(x == n-1 and y == m-1) extra++;
                    if(fireSpread[x][y] + extra > dis[u][v]+1){
                        dis[x][y] = dis[u][v] +1;
                        q.push({x,y});
                    }
                }
            }
        }
        return dis[n-1][m-1] < INF;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        ////// make fireSpread matrix using multi-bfs
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> fireSpread(n, vector<int>(m, INF));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    fireSpread[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto p = q.front();
            int u = p.first, v = p.second;
            q.pop();
            for(int i=0; i<4; i++){
                int x = u+dx[i], y = v+dy[i];
                if(x>=0 and y>=0 and x<n and y<m and grid[x][y] != 2 and fireSpread[x][y] > fireSpread[u][v]+1){
                    fireSpread[x][y] = fireSpread[u][v]+1;
                    q.push({x,y});
                }
            }
        }
        /// binary search on time to and find if path between 
        /// initial position and the final position is possible
        /// by using simple bfs or dfs
        int lo = 0, hi = 1e8, ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(Predicate(fireSpread, mid, grid)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        if(ans >= 1e8) ans = 1e9;
        return ans;
    }
};
