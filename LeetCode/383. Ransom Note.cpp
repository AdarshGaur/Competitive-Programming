// Author: @AdarshGaur

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int f[26] = {};
        for(char& c: magazine)
            f[c-'a']++;
        for(char& c: ransomNote)
            f[c-'a']--;
        for(int& i: f)
            if(i < 0)
                return false;
        return true;
    }
};
