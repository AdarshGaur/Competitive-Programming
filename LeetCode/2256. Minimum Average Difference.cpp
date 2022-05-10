// Author : @AdarshGaur

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long pref = 0, suf = accumulate(nums.begin(), nums.end(), 0ll);
        int mn = INT_MAX, indx = -1;
        for(int i=0; i<n; i++){
            pref += nums[i];
            suf -= nums[i];
            int p = pref/(i+1);
            int s = (i == n-1) ? 0 : suf/(n-1-i);
            if(abs(p-s) < mn)
                mn = abs(p-s), indx = i;
        }
        return indx;
    }
};
