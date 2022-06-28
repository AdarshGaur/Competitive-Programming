// Author : @AdarshGaur

class Solution {
public:
    const int mod = 1e9 +7;    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        vector<long> dp(n, 1), time(n, 0);
        for(auto &e: roads){
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();
            for(auto &[v, w]: g[u]){
                if(time[v] == 0 or time[v] >= t+w){
                    if(time[v] == t+w){
                        dp[v] += dp[u];
                        dp[v] %= mod;
                    }else{
                        time[v] = t+w;
                        dp[v] = dp[u];
                        pq.push({time[v], v});
                    }
                }
            }
        }
        return dp[n-1];
    }
};
