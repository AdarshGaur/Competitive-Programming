// Author: @AdarshGaur

class Solution {
public:

    struct DSU{
        vector<int> par, weight;
        int components, nodes;

        DSU(int n){
            nodes = n;
            components = n;
            par.resize(n+1);
            weight.resize(n+1, 1);
            iota(par.begin(), par.end(), 0);
        }

        int Find(int v){ // find set with path compression
            if(v==par[v])
                return v;
            return par[v] = Find(par[v]);
        }

        bool Union(int a, int b){
            a = Find(a), b = Find(b);
            if(a == b) return false;
            if(weight[a] > weight[b]){
                swap(a,b);
            }
            par[a] = b;
            weight[b] += weight[a];
            components -= 1;
            return true;
        }

        int CntofComponent(){ // return the total number of components
            return components;
        }

        int NodeinComponent(int x){ // return the number of nodes in component x;
            return weight[Find(x)];
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int to_remove = 0;
        for(auto &e: edges){
            if(e[0] == 3){
                if(!dsu.Union(e[1], e[2])){
                    to_remove += 1;
                }
            }
        }
        DSU dsu_2 = dsu;
        for(auto &e: edges){
            if(e[0] == 1){
                if(!dsu.Union(e[1], e[2]))
                    to_remove += 1;
            }else if(e[0] == 2){
                if(!dsu_2.Union(e[1], e[2]))
                    to_remove += 1;
            }
        }
        return dsu.CntofComponent() == 1 and dsu_2.CntofComponent() == 1 ? to_remove : -1;
    }
};

