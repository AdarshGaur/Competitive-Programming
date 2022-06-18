// Author : @AdarshGaur

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), mxlen = 1, indx=0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            for(int j=0; j<i; j++){
                if(s[i] == s[j] and (j+1 == i or dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(mxlen < i-j+1){
                        mxlen = i-j+1;
                        indx = j;
                    }
                }
            }
        }
        return s.substr(indx, mxlen);
    }
};
