// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n-2; j++){
                if(j > i+1 and nums[j] == nums[j-1]) continue;
                long l = j+1, r = n-1, left = (long)target - nums[i] - nums[j];
                while(l < r){
                    int sum = nums[l] + nums[r];
                    if(left == sum){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l<r and nums[l] == nums[l-1]) l++;
                    }else if(sum < left){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
