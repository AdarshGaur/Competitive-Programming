// Author : @AdarshGaur

class Solution {
public:
    vector<int> ans;
    
    bool dfs(vector<vector<int>>& g, vector<int>& vis, int cur){
        if(vis[cur] == 1) return false;
        if(vis[cur] == 2) return true;
        vis[cur] = 1;
        for(int& i: g[cur]){
            if(!dfs(g, vis, i))
                return false;
        }
        vis[cur] = 2;
        ans.push_back(cur);
        return true;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if(n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        for(auto e: pre){
            g[e[0]].push_back(e[1]);
        }
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                if(!dfs(g, vis, i))
                    return {};
            }
        }
        return ans;
    }
};
