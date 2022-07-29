// Author : @AdarshGaur

class Solution {
public:
    
    string f(string s){
        map<char, int> mp;
        for(auto &c: s){
            if(!mp.count(c))
                mp[c] = mp.size();
        }
        for(int i=0; i<s.size(); i++){
            s[i] = 'a' + mp[s[i]];
        }
        return s;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        string s = f(p);
        for(auto &w: words){
            if(f(w) == s)
                ans.push_back(w);
        }
        return ans;
    }
};
