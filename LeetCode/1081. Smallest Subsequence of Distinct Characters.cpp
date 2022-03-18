// Author : Adarsh Gaur

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> done(26, false);
        for(auto i: s){
            freq[i-'a']++;
        }
        string res = "a";
        for(auto i: s){
            int x = i - 'a';
            freq[x]--;
            if(done[x])continue;
            while(i < res.back() and freq[res.back() - 'a']){
                done[ res.back() - 'a'] = false;
                res.pop_back();
            }
            res += i;
            done[x]=true;
        }
        return res.substr(1);
    }
};

