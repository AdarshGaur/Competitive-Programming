// Author: @AdarshGaur

class Solution {
public:
    struct DSU{
        vector<int> par, maxValue, count;
        
        DSU(int n, vector<int>& vals){
            par.resize(n);
            maxValue.resize(n);
            count.resize(n, 1);
            iota(par.begin(), par.end(), 0);
            
            for(int i=0; i<n; i++){
                maxValue[i] = vals[i];
            }
        }
        
        int Find(int a){
            if(a == par[a]) return a;
            return par[a] = Find(par[a]);
        }
        
        int Union(int a, int b){
            int add = 0;
            a = Find(a), b = Find(b);
            if(maxValue[a] == maxValue[b]){
                par[a] = b;
                add = count[a] * count[b];
                count[b] += count[a];
            }else if(maxValue[a] < maxValue[b]){
                par[a] = b;
            }else{
                par[b] = a;
            }
            return add;
        }
    };
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        sort(begin(edges), end(edges), [&](vector<int>& a, vector<int>& b){
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]) ;
        });
        int n = vals.size();
        DSU dsu(n, vals);
        int ans = n;
        for(auto &e: edges){
            ans += dsu.Union(e[0], e[1]);
        }
        return ans;
    }
};
