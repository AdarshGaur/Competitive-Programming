// Author : AdarshGaur

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int lastdiff=INT_MAX, lastans=0, ans=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == lastdiff){
                ans += ++lastans;
            }else{
                lastdiff = nums[i]-nums[i-1];
                lastans=0;
            }
        }
        return ans;
    }
};
