// Author : Adarsh Gaur

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j = s.size()-1;
        while( i < j){
            if(s[i] >= 'A' and s[i] <= 'Z') s[i] += 32;
            if(s[j] >= 'A' and s[j] <= 'Z') s[j] += 32;
            if(s[i] < '0' or (s[i] > '9' and s[i] < 'a') or s[i] > 'z') i++;
            else if(s[j] < '0' or (s[j] > '9' and s[j] < 'a') or s[j] > 'z') j--;
            else if(s[i] != s[j]) return false;
            else i++, j--;
        }
        return true;
    }
};
