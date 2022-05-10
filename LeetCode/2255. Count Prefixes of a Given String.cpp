// Author : @AdarshGaur

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(auto v: words){
            int n = v.size();
            if(v == s.substr(0, n))
                ans++;
        }
        return ans;
    }
};
