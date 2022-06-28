// Author : @AdarshGaur

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        for(auto &e: prerequisites){
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: g[u]){
                dp[v][u] = true;
                if(--indeg[v] == 0){
                    q.push(v);
                }
                for(int j=0; j<n; j++){
                    dp[v][j] = dp[v][j] or dp[u][j];
                }
            }
        }
        vector<bool> ans;
        for(auto& q: queries){
            ans.push_back(dp[q[1]][q[0]]);
        }
        return ans;
    }
};
