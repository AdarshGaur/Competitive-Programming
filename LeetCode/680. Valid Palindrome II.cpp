// Author : Adarsh Gaur

class Solution {
public:
    bool isPalindrome(string s){
        string p(s.rbegin(), s.rend());
        return p == s;
    }
    bool validPalindrome(string s) {
        int i=0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]){
                if(isPalindrome(s.substr(i+1, j-i))) return true;
                else if(isPalindrome(s.substr(i,j-i))) return true;
                return false;
            }
            i++, j--;
        }
        return true;
    }
};
