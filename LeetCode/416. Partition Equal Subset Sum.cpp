// Author : @AdarshGaur

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum &1) return false;
        sum >>= 1;
        int n = nums.size();
        bool dp[n+1][sum+1];
        memset(dp, false, sizeof(dp));
        for(int i=0; i<n+1; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<=sum; i++){
            dp[0][i] = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if( j >= nums[i-1])
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};
