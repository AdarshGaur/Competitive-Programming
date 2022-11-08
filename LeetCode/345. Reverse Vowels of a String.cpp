// Author: @AdarshGaur

class Solution {
public:
    
    bool isVowel(char& c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
        if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            while(left < right and !isVowel(s[left])) left++;
            while(left < right and !isVowel(s[right])) right--;
            if(left >= right) break;
            swap(s[left], s[right]);
            left++, right--;
        }
        return s;
    }
};
