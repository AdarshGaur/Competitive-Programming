// Author: @AdarshGaur

class Solution {
public:
    const int dif = 'z' - 'Z';
    
    bool areSameLetters(char a, char b){
        if(a < 'a' and b < 'a') return false;
        if(a >= 'a' and b >= 'a') return false;
        if(a < 'a') a += dif;
        if(b < 'a') b += dif;
        return a == b;
    }
    
    string makeGood(string s) {
        string ans;
        for(auto &c: s){
            if(!ans.empty() and areSameLetters(ans.back(), c))
                ans.pop_back();
            else
                ans += c;
        }
        return ans;
    }
};
