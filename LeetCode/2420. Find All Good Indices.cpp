// Author : @AdarshGaur

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 1), suf(n, 1);
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1]) pref[i] = pref[i-1] +1;
            else pref[i] = 1;
            
            if(nums[n-i-1] <= nums[n-i]) suf[n-i-1] = suf[n-i] +1;
            else suf[n-i-1] = 1;
        }
        
        vector<int> ans;
        for(int i=k; i<n-k; i++){
            if(pref[i-1] >= k and suf[i+1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};
