// Author : @AdarshGaur

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "#";
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(res[j] == s[i])
                res.pop_back(), j--;
            else
                res += s[i], j++;
        }
        return res.substr(1);
    }
};
