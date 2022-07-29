// Author : @AdarshGaur

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1, vector<string>());
        dp[0].push_back("");
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                int r = i - j -1;
                for(int k=0; k<dp[j].size(); k++){
                    for(int l=0; l<dp[r].size(); l++){
                        dp[i].push_back("(" + dp[j][k] + ")" + dp[r][l]);
                    }
                }
            }
        }
        return dp[n];
    }
    
    void backtrack(vector<string>& ans, string &s, int open, int close, int& n){
        if(s.size() == n*2){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s += "(";
            backtrack(ans, s, open+1, close, n);
            s.pop_back();
        }
        if(close < open){
            s += ")";
            backtrack(ans, s, open, close+1, n);
            s.pop_back();
        }
    }
};
