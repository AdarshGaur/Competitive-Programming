// Author : @AdarshGaur

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() -1, min;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] <= nums.back()){
                hi = mid -1;
                min = nums[mid];
            }else{
                lo = mid +1;
            }
        }
        return min;
    }
};
