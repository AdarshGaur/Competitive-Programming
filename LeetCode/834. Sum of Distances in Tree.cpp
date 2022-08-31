// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> g;
    
    void dfs1(int u, int par, vector<int>& child, vector<int>& sum){
        for(auto v: g[u]){
            if(v == par) continue;
            dfs1(v, u, child, sum);
            sum[u] += sum[v] + child[v] +1;
            child[u] += child[v] +1;
        }
    }
    
    void dfs2(int& n,int u, int par, vector<int>& child, vector<int>& sum){
        for(auto v: g[u]){
            if(v == par) continue;
            sum[v] += (sum[u] - sum[v] - child[v] -1 + n - child[v] -1);
            dfs2(n, v, u, child, sum);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto &e: edges){
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        
        vector<int> child(n,0), sum(n, 0);
        //// first compute the distances it get through it's children
        dfs1(0, -1, child, sum);
        
        //// second compute the distances it get throuh it's parent
        dfs2(n, 0, -1, child, sum);
        
        return sum;
    }
};
