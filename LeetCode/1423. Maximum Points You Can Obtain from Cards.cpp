// Author : @AdarshGaur

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int dp[n+1];
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1] + cardPoints[n-i];
        }
        int ans = dp[k], cnt{};
        for(int i=1; i<=k; i++){
            cnt += cardPoints[i-1];
            ans = max(ans, cnt+dp[k-i]);
        }
        return ans;
    }
};
