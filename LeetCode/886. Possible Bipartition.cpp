// Author: @AdarshGaur

class Solution {
public:

    vector<vector<int>> g;
    vector<int> color;
    bool isBipartite = true;

    void dfs(int cur, int c){
        color[cur] = c;
        for(auto &v: g[cur]){
            if(color[v] == c){
                isBipartite = false;
            }
            if(color[v] == -1){
                dfs(v, c^1);
            }
            if(!isBipartite)
                return;
        }
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g = vector<vector<int>>(n);
        for(auto &e: dislikes){
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        color.resize(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                dfs(i, 0);
            }
            if(!isBipartite) break;
        }
        return isBipartite;
    }
};
