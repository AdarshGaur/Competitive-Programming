// Author : @AdarshGaur

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string, int> dp;
        int ans{};
        sort(words.begin(), words.end(), [&](string a, string b){
            return a.size() < b.size();
        });
        for(int i=0; i<words.size(); i++){
            int mx = 0;
            for(int j=0; j<words[i].size(); j++){
                string s = words[i].substr(0, j) + words[i].substr(j+1);
                if(dp.count(s)){
                    mx = max(mx, dp[s]);
                }
            }
            dp[words[i]] = mx +1;
            ans = max(ans, mx+1);
        }
        return ans;
    }
};
