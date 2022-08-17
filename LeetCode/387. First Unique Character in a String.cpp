// Author : @AdarshGaur

class Solution {
public:
    int firstUniqChar(string s) {
        int f[26] = {};
        for(char& c: s)
            f[c-'a']++;
        for(int i=0; i<s.size(); i++)
            if(f[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};
