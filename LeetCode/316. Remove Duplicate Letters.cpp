// Author : Adarsh Gaur

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0), done(26, 0);
        for(auto i: s){
            freq[i-'a']++;
        }
        string res = "a";
        for(auto i: s){
            int x = i - 'a';
            freq[x]--;
            if(done[x])continue;
            while(i < res.back() and freq[res.back() - 'a']){
                done[ res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += i;
            done[x]++;
        }
        return res.substr(1);
    }
};

