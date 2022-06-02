// Author : @AdarshGaur

class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans;
        ans += s[0];
        for(int i=1; i<(int)s.size(); i++){
            if(!ans.empty() and ans.back() > s[i] and k){
                ans.pop_back();
                k--;
                i--;
            }else{
                ans.push_back(s[i]);
            }
        }
        while(!ans.empty() and k){
            ans.pop_back();
            k--;
        }
        int i =0;
        while(i < ans.size() and ans[i] == '0') i++;
        if(i == ans.size()) return "0";
        return ans.substr(i);
    }
};
