// Author: @AdarshGaur

class Solution {
public:
    vector<int> par;

    int Find(int u){
        if(par[u] == u) return u;
        return par[u] = Find(par[u]);
    }

    void Union(int a, int b){
        a = Find(a), b = Find(b);
        if(a == b){
            return;
        }else if(a < b){
            par[b] = a;
        }else{
            par[a] = b;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(26);
        iota(par.begin(), par.end(), 0);
        for(int i=0; i<s1.size(); i++){
            Union(s1[i] - 'a', s2[i] - 'a');
        }
        string ans;
        for(auto &c: baseStr){
            ans += 'a' + Find(c - 'a');
        }
        return ans;
    }
};
