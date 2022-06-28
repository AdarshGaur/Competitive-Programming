// Author : @AdarshGaur

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);
        for(auto e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++, deg[e[1]]++;
        }
        vector<int> leafs;
        for(int i=0; i<n; i++){
            if(deg[i] == 1)
                leafs.push_back(i);
        }
        int nodesLeft = n;
        while(nodesLeft > 2){
            vector<int> tleafs;
            for(auto i: leafs){
                deg[i]--;
                nodesLeft--;
                for(auto j: g[i]){
                    deg[j] += (deg[j] > 1 ? -1 : 0);
                    if(deg[j] == 1)
                        tleafs.push_back(j);
                }
            }
            swap(tleafs, leafs);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(deg[i] != 0)
                ans.push_back(i);
        }
        assert(ans.size() <= 2);
        return ans;
    }
};
