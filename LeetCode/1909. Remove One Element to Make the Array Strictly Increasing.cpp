// Author : @AdarshGaur

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool removed = false;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(prev < nums[i]){
                prev = nums[i];
                continue;
            }
            if(removed) return false;
            removed = true;
            if(i == 1 or nums[i] > nums[i-2])
                prev = nums[i];
        }
        return true;
    }
};
