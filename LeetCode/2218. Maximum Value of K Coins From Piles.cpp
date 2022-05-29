// Author : @AdarshGaur

class Solution {
public:
    int dp[1001][2001]{};    
    int fun(vector<vector<int>>& p, int i, int k){
        if(i == p.size() or k == 0) return 0;
        if(dp[i][k] > 0) return dp[i][k];
        int ans = fun(p, i+1, k), sum = 0;
        for(int j=0; j<p[i].size() && j<k; j++){
            sum += p[i][j];
            ans = max(ans, sum + fun(p, i+1, k-1-j));
        }
        dp[i][k] = ans;
        return dp[i][k];
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return fun(piles, 0, k);
    }
};
