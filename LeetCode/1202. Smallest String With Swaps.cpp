// Author : @AdarshGaur

class Solution {
public:
    struct DSU{
        vector<int> par, weight;
        DSU(int n){
            par.resize(n);
            weight.resize(n, 1);
            iota(par.begin(), par.end(), 0);
        }
        
        int Find(int u){
            if(par[u] == u) return u;
            return par[u] = Find(par[u]);
        }
        
        bool Union(int a, int b){
            a = Find(a), b = Find(b);
            if(a == b) return false;
            if(weight[a] > weight[b])
                swap(a, b);
            weight[b] += weight[a];
            par[a] = b;
            return true;
        }
    };
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for(auto v: pairs)
            dsu.Union(v[0], v[1]);
        vector<vector<int>> mp(n);
        for(int i=0; i<n; i++)
            mp[dsu.Find(i)].push_back(i);        
        for(auto v : mp){
            string t = "";
            for(auto ind : v){
                t += s[ind];
            }
            sort(t.rbegin(), t.rend());
            for(auto ind: v){
                s[ind] = t.back();
                t.pop_back();
            }
        }
        return s;
    }
};
