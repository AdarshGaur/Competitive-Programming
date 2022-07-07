// Author : @AdarshGaur

class Solution {
public:
    struct DSU{
        int mxsize;
        vector<int> par, weight;
        
        DSU(int n){
            mxsize = 1;
            par.resize(n+1);
            iota(par.begin(), par.end(), 0);
            weight.resize(n+1, 1);
        }
        
        int find(int a){
            if(par[a] == a) return a;
            return par[a] = find(par[a]);
        }
        
        bool Union(int a, int b){
            a = find(a), b = find(b);
            if(a == b) return false;
            if(weight[a] > weight[b])
                swap(a, b);
            par[a] = b;
            weight[b] += weight[a];
            mxsize = max(mxsize, weight[b]);
            return true;
        }
    };
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        DSU dsu(n);
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            if(mp[nums[i]]) continue;
            if(mp[nums[i]-1])
                dsu.Union(mp[nums[i]-1], i+1);
            if(mp[nums[i]+1])
                dsu.Union(mp[nums[i]+1], i+1);
            mp[nums[i]] = i+1;
        }
        return dsu.mxsize;
    }
};
