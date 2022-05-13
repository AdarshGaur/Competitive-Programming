// Author : @AdarshGaur

class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, cur=0;
        int freq[26] = {};
        for(int i=0; i<s.size(); i++){
            cur += i+1 - freq[s[i]-'a'];
            freq[s[i]-'a'] = i+1;
            ans += cur;
        }
        return ans;
    }
};
