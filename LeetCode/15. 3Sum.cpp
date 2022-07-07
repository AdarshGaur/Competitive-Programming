// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i+2<nums.size(); i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k and nums[k] == nums[k-1]) k--;
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};
