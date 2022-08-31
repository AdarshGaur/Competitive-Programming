// Author: @AdarshGaur

class Solution {
public:
    
    struct DSU{
        vector<long long> par, weight;
        
        DSU(int n){
            par.resize(n);
            iota(par.begin(), par.end(), 0);
            weight.resize(n, 1);
        }
        
        long long Find(int a){
            if(a == par[a])
                return a;
            return par[a] = Find(par[a]);
        }
        
        bool Union(int a, int b){
            a = Find(a), b = Find(b);
            if(a == b) return false;
            if(weight[a] < weight[b])
                swap(a, b);
            weight[a] += weight[b];
            par[b] = a;
            return true;
        }
        
        long long Count(int a){
            return weight[Find(a)];
        }
        
    };
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto& e: edges){
            dsu.Union(e[0], e[1]);
        }
        
        long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (n - dsu.Count(i));
        }
        cnt >>=1;
        return cnt;
    }
};
