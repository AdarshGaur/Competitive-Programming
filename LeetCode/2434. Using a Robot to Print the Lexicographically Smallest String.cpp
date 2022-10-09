// Author : @AdarshGaur

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suf(n+1, 'z');
        for(int i=n-1; i>=0; i--){
            suf[i] = min(s[i], suf[i+1]);
        }
        string ans, t;
        for(int i=0; i<n; i++){
            while(!t.empty() and t.back() <= suf[i]){
                ans += t.back();
                t.pop_back();
            }
            t += s[i];
        }
        reverse(t.begin(), t.end());
        return ans + t;
    }
};
