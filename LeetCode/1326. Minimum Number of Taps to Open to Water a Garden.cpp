// Author: @AdarshGaur

class Solution {
public:
    // int minTaps(int n, vector<int>& ranges) {
    //     vector<vector<int>> R;
    //     for(int i=0; i<=n; i++){
    //         auto &r = ranges[i];
    //         R.push_back({i-r, i+r});
    //     }
    //     sort(begin(R), end(R));
    //     int r = 0, l = 0, cnt = 0;
    //     while(r < n){
    //         int mx = r;
    //         while(l <= n && R[l][0] <= r){
    //             mx = max(mx, R[l][1]);
    //             l++;
    //         }
    //         if(mx == r) return -1;
    //         r = mx;
    //         cnt += 1;
    //     }
    //     return cnt;
    // }

    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, n+7);
        dp[0] = 0;
        for(int i=0; i<=n; i++){
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            for(int j=l+1; j<=r; j++){
                dp[j] = min(dp[j], dp[l] +1);
            }
        }
        if(dp[n] == n+7) return -1;
        return dp[n];
    }
};
