// Author : @AdarshGaur

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1, ans = 0;
        while(i<j){
            if(nums[i] + nums[j] == k)
                ans++, i++, j--;
            else if(nums[i] + nums[j] > k)
                j--;
            else
                i++;
        }
        return ans;
    }
};
