// Author: @AdarshGaur

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n+1, 0);
        for(auto &v: trust){
            // outdegree is referred as -ve value
            // indegree is referred as +ve value
            deg[v[0]]--, deg[v[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(deg[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};
