// Author : @AdarshGaur

class Solution {
public:
    int timer = 1;
    vector<vector<int>> ans, adj;
    vector<int> in, low;
    vector<bool> vis;
    void dfs(int cur, int par = -1){
        vis[cur] = true;
        in[cur] = low[cur] = timer++;
        for(auto to: adj[cur]){
            if(to == par) continue;
            if(vis[to]){
                low[cur] = min(low[cur], in[to]);
            }else{
                dfs(to, cur);
                low[cur] = min(low[cur], low[to]);
                if(low[to] > in[cur]){
                    ans.push_back({cur, to});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis = vector<bool>(n, false);
        low = in = vector<int>(n, 0);
        adj = vector<vector<int>>(n);
        for(auto &v: connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(0);
        return ans;
    }
};
