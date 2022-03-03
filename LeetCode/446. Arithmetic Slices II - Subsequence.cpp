// Author : AdarshGaur

class Solution {
public:
    #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
        // O(n^2)
        ll n = nums.size(), ans=0;
        vector<unordered_map<ll,ll>> dp(n, unordered_map<ll,ll>());
        for(ll i=1; i<n; i++){
            for(auto j=i-1; j>=0; j--){
                ll dif = (ll)nums[i] - nums[j];
                ll cnt = dp[j].count(dif) ? dp[j][dif] : 0;
                dp[i][dif] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};
