// Author : @AdarshGaur

class Solution {
public:
    int memo[101][21][101];
    
    int dp(vector<int>& houses, vector<vector<int>>& cost, int target, int i, int color){
        if(i >= houses.size() or target < 0){
            if(target == 0) return target;
            return 1e6 +7;
        }
        if(houses[i] != 0)
            return dp(houses, cost, target - (color != houses[i]), i+1, houses[i]);
        if(memo[i][color][target] != -1) return memo[i][color][target];
        int ans = 1e6 +7;
        for(int j=1; j<=cost[0].size(); j++){
            ans = min(ans, cost[i][j-1] + dp(houses, cost, target - (color != j), i+1, j));
        }
        memo[i][color][target] = ans;
        return ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof(memo));
        int ret = dp(houses, cost, target, 0, 0);
        return ret > 1e6 ? -1 : ret;
    }
};
