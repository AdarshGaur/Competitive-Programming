// Author: @AdarshGaur

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int> mp1;
        map<string, int> mp2;
        string cur;
        s += " ";
        int p = 0, i = 0;
        for( ; i<s.size() and p < pattern.size(); i++){
            if(s[i] != ' '){
                cur += s[i];
                continue;
            }
            if(!mp2.count(cur)) mp2[cur] = p;
            if(!mp1.count(pattern[p])) mp1[pattern[p]] = p;
            if(mp1[pattern[p]] != mp2[cur]) return false;
            cur = "";
            p += 1;
        }
        return mp1.size() == mp2.size() and p == pattern.size() and i == s.size();
    }
};
