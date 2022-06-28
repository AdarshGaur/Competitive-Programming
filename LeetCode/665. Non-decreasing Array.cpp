// Author : @AdarshGaur

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1] and nums[i-1] > nums[i]) return false;
            if(nums[i] <= nums[i+1] and nums[i-1] <= nums[i]) continue;
            if(nums[i-1] <= nums[i]){
                if(nums[i-1] > nums[i+1]) nums[i+1] = nums[i];
                else nums[i] = nums[i-1];
            }else{
                if(nums[i-1] > nums[i+1]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
            cnt++;
        }
        return cnt <= 1;
    }
};
