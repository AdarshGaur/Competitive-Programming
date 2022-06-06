// Author : @AdarshGaur

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
        for(int i=0; i<=n; i++){
            int ind = lower_bound(dp.begin(), dp.end(), target+dp[i]) - dp.begin();
            if(ind <= n) ans = min(ans, ind - i);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
