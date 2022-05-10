// Author : @AdarshGaur

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>();
        vector<string> res(1, "");
        string mp[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(auto i: digits){
            vector<string> temp;
            for(auto s: res)
                for(auto k: mp[i-'0'])
                    temp.push_back(s+k);
            res = temp;
        }
        return res;
    }
};
