// Author : @AdarshGaur

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans{};
        for(int& i: nums)
            ans |= i;
        return ans << (nums.size() -1);
    }
};
