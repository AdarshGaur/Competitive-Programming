// Author : @AdarshGaur

class Solution {
public:
    
    struct DSU{
        vector<int> par, weight;

        DSU(int n){
            weight.resize(n+1, 1);
            par.resize(n+1);
            iota(par.begin(), par.end(), 0);
        }
        
        int find(int v){
            if(par[v] == v)
                return v;
            return par[v] = find(par[v]);
        }
        
        bool Union(int a, int b){
            a = find(a), b = find(b);
            if(a == b)
                return false;
            if(weight[a] < weight[b])
                swap(a, b);
            weight[a] += weight[b];
            par[b] = a;
            return true;
        }
        
    };
    
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto &v: equations){
            if(v[1] == v[2])
                dsu.Union(v[0] - 'a', v[3] - 'a');
        }
        for(auto &v: equations){
            if(v[1] != v[2] and dsu.find(v[0]-'a') == dsu.find(v[3]-'a'))
                return false;
        }
        return true;
    }
};
