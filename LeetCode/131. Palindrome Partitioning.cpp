// Author : @AdarshGaur

class Solution {
public:
    
    void dfs(string& s, vector<vector<string>>& ans, vector<string>& path, int indx){
        if(indx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = indx; i<s.size(); i++){
            if(isPalin(s, indx, i)){
                path.push_back(s.substr(indx, i-indx +1));
                dfs(s, ans, path, i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPalin(string& s, int i, int j){
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(s, ans, path, 0);
        return ans;
    }
    
    // Iterative DP Solution (less Space efficient)
    // vector<vector<string>> partition(string s) {
    //     int n = s.size();
    //     vector<vector<string>> dp[n+1];
    //     dp[0] = {{}};
    //     for(int i=0; i<n; i++){
    //         for(int j=i; j<n; j++){
    //             if(isPalin(s, i, j)){
    //                 for(auto v: dp[i]){
    //                     v.push_back(s.substr(i, j-i+1));
    //                     dp[j+1].push_back(v);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
};
