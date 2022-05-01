// Author : @AdarshGaur

class Solution {
public:
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(graph, i, 0))
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& g, int cur, int c){
        color[cur] = c;
        for(auto v: g[cur]){
            if(color[v] == -1){
                if(!dfs(g, v, c^1))
                    return false;
            }
            if(color[cur] == color[v])
                return false;
        }
        return true;
    }
};
