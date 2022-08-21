// Author : @AdarshGaur

class Solution {
public:
    // int minCut(string s) {
    //     int n = s.size();
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[0] = 0;
    //     vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    //     for(int i=0; i<n; i++){
    //         for(int j = i; j>=0; j--){
    //             if(s[i] == s[j] and (i - j <= 2 or isPalin[j+1][i-1])){
    //                 isPalin[j][i] = true;
    //                 if(dp[j] == INT_MAX) continue;
    //                 dp[i+1] = min(dp[i+1], dp[j] +1);
    //             }
    //         }
    //     }
    //     return dp[n]-1;
    // }
    
    int minCut(string s){
        int n = s.size();
        int dp[n+1];
        for(int i=0; i<=n; i++)
            dp[i] = i-1;
        for(int i=0; i<n; i++){
            // palindrome of odd length
            for(int j=0; i+j<n and i-j>=0 and s[i+j] == s[i-j]; j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
            
            // palindrome of even length
            for(int j=0; i+j<n and i-j>0 and s[i-j-1] == s[i+j]; j++)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
        }
        return dp[n];
    }
};
