// Author: @AdarshGaur

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> g[n];
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: g[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                    if(v == destination)
                        return true;
                }
            }
        }
        return false;
    }
};
