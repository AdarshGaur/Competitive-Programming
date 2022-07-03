// Author : @AdarshGaur

class Solution {
public:
    int f(vector<int>& a, int& n, int start, int end){
        vector<int> dp(n+1, 0);
        dp[start] = a[start-1];
        int ret = dp[start];
        for(int i=start+1; i<=end; i++){
            if(i < 3){
                dp[i] = a[i-1] + dp[i-2];
                continue;
            }
            dp[i] = max(dp[i-2], dp[i-3]) + a[i-1];
            ret = max(ret, dp[i]);
        }
        return ret;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.back();
        return max(f(nums, n, 1, n-1), f(nums, n, 2, n));
    }
};
