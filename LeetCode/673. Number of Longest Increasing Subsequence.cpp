// Author : @AdarshGaur

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), mx{};
        vector<pair<int,int>> dp(n); // {lenofLIS, cntofLIS}
        for(int i=0; i<n; i++){
            dp[i] = {1, 0};
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i] and dp[j].first >= dp[i].first)
                    dp[i].first = dp[j].first+1;
            }
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i] and dp[j].first == dp[i].first-1)
                    dp[i].second += dp[j].second;
            }
            dp[i].second = max(dp[i].second, 1);
            mx = max(mx, dp[i].first);
        }
        int ans{};
        for(int i=0; i<n; i++){
            if(dp[i].first == mx)
                ans += dp[i].second;
        }
        return ans;
    }
};
