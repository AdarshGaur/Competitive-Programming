// Author: @AdarshGaur

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 0), rLIS(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[j] +1, LIS[i]);
                }
                if(nums[n-1 -i] > nums[n-1 -j]){
                    rLIS[n-1 -i] = max(rLIS[n-1 -j] +1, rLIS[n-1 -i]);
                }
            }
        }
        int mx = 0;
        for(int i=1; i<n-1; i++){
            if(LIS[i] == 0 or rLIS[i] == 0) continue;
            mx = max(mx, LIS[i] + rLIS[i] +1);
        }
        return n - mx;
    }
};
