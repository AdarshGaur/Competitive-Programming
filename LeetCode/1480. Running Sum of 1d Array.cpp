// Author : @AdarshGaur

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> dp(1, nums[0]);
        for(int i=1; i<nums.size(); i++)
            dp.push_back(dp.back() +  nums[i]);
        return dp;
    }
};
