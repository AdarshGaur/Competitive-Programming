// Author : Adarsh Gaur

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = (l+r)>>1;
            if(nums[m] < target){
                l = m+1;
            }else if(nums[m] > target){
                r = m-1;
            }else{
                return m;
            }
        }
        return -1;
    }
};
