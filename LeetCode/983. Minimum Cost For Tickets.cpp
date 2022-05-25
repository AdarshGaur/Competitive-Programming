// Author : @AdarshGaur

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        int j=0, n = days.size();
        for(int i=1; i<366; i++){
            if(days[j] != i){
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min(dp[i], dp[i-1] + costs[0]);
            dp[i] = min(dp[i], dp[max(0, i-7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);
            j++;
            if(j == days.size()) break;
        }
        return dp[days.back()];
    }
};
