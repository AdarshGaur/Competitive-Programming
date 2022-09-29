// Author : @AdarshGaur

class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        for(char& c:s){
            if(c != ' '){
                temp += c;
            }else{
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
                temp = "";
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};
