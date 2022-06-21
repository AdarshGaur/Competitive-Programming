// Author : @AdarshGaur

class Solution {
public:
    string greatestLetter(string s) {
        int small[26]{}, big[26]{};
        for(auto i: s){
            if(i >= 'a') small[i-'a']++;
            else big[i-'A']++;
        }
        string ans;
        for(int i=0; i<26; i++)
            if(small[i] and big[i])
                ans = 'A' + i;
        return ans;
    }
};
