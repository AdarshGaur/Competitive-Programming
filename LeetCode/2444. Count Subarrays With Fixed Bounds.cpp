// Author: @AdarshGaur

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, j_ = -1, jmin = -1, jmax = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < minK or nums[i] > maxK) j_ = i;
            if(nums[i] == minK) jmin = i;
            if(nums[i] == maxK) jmax = i;
            ans += max<long long>(0, min(jmin, jmax) - j_);
        }
        return ans;
    }
};

