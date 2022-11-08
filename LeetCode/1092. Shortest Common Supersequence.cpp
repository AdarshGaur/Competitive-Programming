// Author : @AdarshGaur

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        // phase 1 : find the LCS
        int n = str1.size(), m = str2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string LIS;
        int i = n, j = m;
        while(i > 0 and j > 0){
            if(str1[i-1] == str2[j-1]){
                LIS += str1[i-1];
                i--, j--;
            }else{
                if(dp[i][j] == dp[i-1][j]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(begin(LIS), end(LIS));
        
        // phase 2 : mark the LCS
        auto change = [&](string& s){
            j = 0;
            for(i = 0; i<s.size(); i++){
                if(s[i] == LIS[j]){
                    s[i] = '#';
                    j++;
                }
            }
            return;
        };
        
        change(str1), change(str2);
        
        // phase 3 : obtain the supersequence
        string res;
        i = 0, j = 0;
        int k = 0;
        while(i < n or j < m or k < LIS.size()){
            if(i < n and str1[i] != '#'){
                res += str1[i++];
            }else if(j < m and str2[j] != '#'){
                res += str2[j++];
            }else{
                res += LIS[k++];
                i++, j++;
            }
        }
        
        return res;
    }
};
