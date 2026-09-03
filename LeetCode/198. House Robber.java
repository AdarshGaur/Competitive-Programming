class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        for(int i=0; i<n; i++){
            int k = i - 2;
            int m = i - 3;
            if(k >= 0 && m >= 0){
                dp[i] = Math.max(dp[k], dp[m]) + nums[i];
            }else if(k >= 0){
                dp[i] = dp[k] + nums[i];
            }else if(m >= 0){
                dp[i] = dp[m] + nums[i];
            }else{
                dp[i] = nums[i];
            }
        }
        return n > 1 ? Math.max(dp[n-2], dp[n-1]) : dp[n-1];
    }
}
