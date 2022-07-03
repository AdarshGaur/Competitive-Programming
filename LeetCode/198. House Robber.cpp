// Author : @AdarshGaur

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.back();
        int l1 = nums[1], l2 = nums[0], l3 = 0;
        for(int i=2; i<n; i++){
            int t = l1;
            l1 = max(l2, l3) + nums[i];
            l3 = l2;
            l2 = t;
        }
        return max(l1, l2);
    }
};
