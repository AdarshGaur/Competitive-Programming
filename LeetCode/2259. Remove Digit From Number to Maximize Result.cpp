// Author : @AdarshGaur

class Solution {
public:
    string removeDigit(string s, char d) {
        int last = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == d){
                last = i;
                if(i+1 < s.size() and s[i] < s[i+1])
                    return s.erase(i,1);
            }
        }
        return s.erase(last, 1);
    }
};
