// Author : @AdarshGaur

class Solution {
public:
    struct DSU{
        vector<int> par, weight;
        DSU(int n){
            par.resize(n+1);
            weight.resize(n+1, 1);
            iota(par.begin(), par.end(), 0);
        }
        
        int find(int a){
            if(par[a] == a)
                return a;
            return par[a] = find(par[a]);
        }
        
        bool Union(int a, int b){
            a = find(a), b = find(b);
            if( a == b)
                return false;
            if(weight[a] < weight[b])
                swap(a, b);
            weight[a] += weight[b];
            par[b] = a;
            return true;
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2, 0);
        DSU dsu(edges.size());
        for(auto &v: edges){
            if(!dsu.Union(v[0], v[1]))
                res[0] = v[0], res[1] = v[1];
        }
        return res;
    }
};
