// Author : @AdarshGaur

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), cnt = 1e5;
        vector<int> ans(n);
        for(int i=0; i<n; i++, cnt++){
            if(s[i] == c) cnt = 0;
            ans[i] = cnt;
        }
        cnt = 1e5;
        for(int i=n-1; i>=0; i--, cnt++){
            if(s[i] == c) cnt = 0;
            ans[i] = min(ans[i], cnt);
        }
        return ans;
    }
};
