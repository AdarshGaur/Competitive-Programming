// Author : @AdarshGaur

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int i = 0, sign = 1;
        while(i < s.size() and s[i] == ' ') i++;
        if(i < s.size() and (s[i] == '-' or s[i] == '+'))
            sign = (s[i++] == '+' ? 1 : -1);
        while(i < s.size() and s[i]<='9' and s[i] >= '0'){
            res = res*10 + (s[i] - '0');
            if(res*sign >= INT_MAX) return INT_MAX;
            if(res*sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return res*sign;
    }
};
