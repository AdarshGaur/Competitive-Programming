// Author : @AdarshGaur

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), cnt=0;
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                cnt++;
            }
        }
        int ans = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            dp[u][colors[u]-'a']++;
            for(auto& v: g[u]){
                if(--indeg[v] == 0){
                    q.push(v);
                    cnt++;
                }
                for(int i=0; i<26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i]);
                }
            }
            ans = max(ans, dp[u][colors[u]-'a']);
        }
        return (cnt == n ? ans : -1);
    }
};
