// Author : @AdarshGaur

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i=0; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--)
                if(nums[j] < nums[i] and dp[i] <= dp[j])
                    dp[i] = dp[j] + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
