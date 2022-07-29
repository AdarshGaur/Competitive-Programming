// Author : @AdarshGaur

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        int f[26] = {};
        for(int i=0; i<s.size(); i++){
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
            if(f[i] != 0)
                return false;
        return true;
    }
};
