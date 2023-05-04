// Author: @AdarshGaur

class Solution {
public:
    struct DSU{
        int nodes, components;
        vector<int> weight, par;

        DSU(int n){
            nodes = n, components = n;
            par.resize(n);
            weight.resize(n, 1);
            iota(par.begin(), par.end(), 0);
        }

        int Find(int u){
            if(par[u] == u)
                return par[u];
            return par[u] = Find(par[u]);
        }

        bool Union(int a, int b){
            a = Find(a), b = Find(b);
            if(a == b) return false;
            if(weight[a] < weight[b]){
                swap(a, b);
            }
            weight[a] += weight[b];
            par[b] = a;
            components -= 1;
            return true;
        }

    };

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // sorted limit array
        vector<tuple<int,int,int,int>> L; // [[limit, p, q, j], ...]
        for(int i = 0; i<queries.size(); i++){
            auto &q = queries[i];
            L.push_back({q[2], q[0], q[1], i});
        }
        sort(begin(L), end(L));

        // Sorted edgelist in dist order
        sort(begin(edgeList), end(edgeList), [&](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        // iterate over edgelist and simultaneously check for limits also
        DSU dsu(n);
        vector<bool> ans(L.size());
        int j = 0;
        for(auto &[l, p, q, i]: L){
            while(j < edgeList.size() and edgeList[j][2] < l){
                dsu.Union(edgeList[j][0], edgeList[j][1]);
                j += 1;
            }
            if(dsu.Find(p) != dsu.Find(q)){
                ans[i] = false;
            }else{
                ans[i] = true;
            }
        }
        return ans;
    }
};

