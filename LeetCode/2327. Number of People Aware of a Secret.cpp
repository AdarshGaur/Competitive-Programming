// Author : @AdarshGaur

class Solution {
public:
    const int mod = 1e9 +7;
    
    // Time Complexity - O(n^2);
    // int peopleAwareOfSecret(int n, int delay, int forget) { 
    //     vector<int> added(n, 0), remeber(n, 0);
    //     added[0] = 1;
    //     remeber[0] = 1;
    //     for(int i=0; i<n; i++){
    //         if(added[i] == 0) continue;
    //         for(int j=0; j<forget and i+j <n; j++){
    //             remeber[i+j] = (remeber[i+j] + added[i]) %mod;
    //             if(j >= delay)
    //                 added[i+j] = (added[i+j] + added[i]) %mod;
    //         }
    //     }
    //     return remeber[n-1];
    // }
    
    
    // Time Complexity - O(n);
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1, 0);
        long share = 0, ans = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            share = (share + dp[max(i-delay, 0)] - dp[max(i - forget, 0)] + mod) %mod;
            dp[i] = share;
            if(i > n - forget)
                ans = (ans + dp[i]) %mod;
        }
        if(n == forget) ans = (ans +1) %mod;
        return ans;
    }
};
