// Author: @AdarshGaur

class Solution {
public:
    bool detectCapitalUse(string s) {
        bool upper = true, lower = true;
        for(int i=1; i<s.size(); i++){
            if(s[i] >= 'a' and s[i] <= 'z') upper = false;
            if(s[i] >= 'A' and s[i] <= 'Z') lower = false;
        }
        return lower or (s[0] >= 'A' and s[0] <= 'Z' and upper);
    }
};
