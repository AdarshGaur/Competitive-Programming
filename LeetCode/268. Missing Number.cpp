// Author : @AdarshGaur

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, n = nums.size();
        for(int i=0; i<= n; i++)
            x ^= i;
        for(int &i: nums)
            x ^= i;
        return x;
    }
};
