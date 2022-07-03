// Author : @AdarshGaur

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), inc = 1, dec = 1;
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1] > 0){
                inc = dec+1;
            }else if(nums[i]-nums[i-1] < 0){
                dec = inc+1;
            }
        }
        return max(inc, dec);
    }
};
