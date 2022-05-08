// Author : @AdarshGaur

class Solution {
public:
    struct DSU{
        vector<int> par, sz;
        int components;
        DSU(int n){
            components = n;
            par.resize(n+1);
            sz.resize(n+1, 1);
            iota(par.begin(), par.end(), 0);
        }
        
        int find(int a){
            if(par[a] == a)
                return a;
            return par[a] = find(par[a]);
        }
        
        bool Union(int a, int b){
            a = find(a), b = find(b);
            if(a == b) return false;
            if(sz[a] > sz[b])
                swap(a, b);
            sz[b] += sz[a];
            par[a] = b;
            components--;
            return true;
        }
        
        int CountComponents(){
            return components;
        }
    };
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), node{};
        vector<int> indeg(n+1, 0);
        vector<vector<int>> res;
        DSU dsu(n);
        for(auto &e : edges){
            indeg[e[1]]++;
            if(indeg[e[1]] > 1){
                node = e[1];
            }
        }
        for(auto &e: edges){
            if(e[1] != node){
                if(!dsu.Union(e[1], e[0])){
                    res.push_back(e);
                }
            }else{
                res.push_back(e);
            }
        }
        if(res.size() == 1) return res[0];
        dsu.Union(res[0][0], res[0][1]);
        if(dsu.CountComponents() != 1)
            return res[0];
        return res[1];
    }
};
