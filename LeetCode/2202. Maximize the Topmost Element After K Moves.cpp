// Author : AdarshGaur

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1){
            k %= 2;
            return (k ? -1 : nums[0]);
        }
        if(k == 0) return nums[0];
        if(k == 1) return nums[1];
        int i=0, mx=-1;
        while(i<nums.size() and k>1){
            k--;
            mx = max(mx, nums[i++]);
        }
        if(i == nums.size() or i == nums.size()-1) return mx;
        return max(mx, nums[i+1]);
    }
};
