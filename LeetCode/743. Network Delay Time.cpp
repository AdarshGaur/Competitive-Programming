// Author : @AdarshGaur

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto &v: times){
            g[v[0]].push_back({v[1], v[2]});
        }
        vector<int> dp(n+1, INT_MAX);
        queue<int> q;
        q.push(k);
        dp[k] = 0;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto &[v, w]: g[u]){
                if(dp[v] > dp[u]+w){
                    q.push(v);
                    dp[v] = dp[u] + w;
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dp[i] == INT_MAX)
                return -1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
