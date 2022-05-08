// Author : @AdarshGaur

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int start = 0, last = nums.size()-1;
        bool ok1 = true, ok2 = true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                ok1 = false;
                while(start >=0){
                    if(nums[start] <= nums[i]) break;
                    start--;
                }
            }else if(ok1){
                start++;
            }
            int r = nums.size()-1-i;
            if(nums[r] > nums[r+1]){
                ok2 = false;
                while(last < nums.size()){
                    if(nums[last] >= nums[r]) break;
                    last++;
                }
            }else if(ok2){
                last--;
            }
        }
        start++;
        last--;
        if(start >= last) return 0;
        return last - start +1;
    }
};
