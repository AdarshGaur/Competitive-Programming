// Author : @AdarshGaur

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), ans = 0;
        vector<int> dp(m, 0);
        for(int i=0; i<m; i++){
            int v = 0;
            for(int k=0; k<i; k++){
                bool pos = true;
                for(auto& s: strs){
                    if(s[k] > s[i]){
                        pos = false;
                        break;
                    }
                }
                if(!pos) continue;
                v = max(dp[k], v);
            }
            dp[i] = v +1;
            ans = max(ans, dp[i]);
        }
        return m - ans;
    }
};
