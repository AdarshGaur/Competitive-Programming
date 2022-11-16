// Author: @AdarshGaur

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        sort(begin(nums), end(nums));
        int amplitude = nums.back() - nums[0];
        for(int i = 0; i<4; i++){
            amplitude = min(amplitude, nums[n-4 +i] - nums[0 + i]);
        }
        return amplitude;
    }
};
