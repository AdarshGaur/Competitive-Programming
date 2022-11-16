// Author: @AdarshGaur

class Solution {
public:
    int numSplits(string s) {
        int ways = 0, unique = 0, n = s.size();
        int found[26] = {};
        int suf[n];
        for(int i = n-1; i>=0; i--){
            if(found[s[i] - 'a'] == 0)
                unique++;
            found[s[i]-'a'] = 1;
            suf[i] = unique;
        }
        
        unique = 0;
        memset(found, 0, sizeof(found));
        
        for(int i=1; i<n; i++){
            if(found[s[i-1]-'a'] == 0)
                unique++;
            found[s[i-1]-'a'] = 1;
            if(suf[i] == unique){
                ways++;
            }
        }
        
        return ways;
    }
};
