// Author : @AdarshGaur

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for(int i=0; i<n; i++){
            int j=0;
            while(i+j<n and i-j>=0 and s[i-j] == s[i+j]) j++;
            ans += j;
            j = 1;
            while(i+j-1<n and i-j>=0 and s[i-j] == s[i+j-1]) j++;
            ans += j-1;
        }
        return ans;
    }
};
