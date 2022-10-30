// Author : @AdarshGaur

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        vector<vector<int>> dp(n, vector<int>(2 ,1));
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1]){
                dp[i][0] = dp[i-1][1] +1;
                ans = max(ans, dp[i][0]);
            }else if(arr[i] < arr[i-1]){
                dp[i][1] = dp[i-1][0] +1;
                ans = max(ans, dp[i][1]);
            }
        }
        return ans;
    }
};
