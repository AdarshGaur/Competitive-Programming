// Author : @AdarshGaur

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int longest = s[0].size();
        for(int i=1; i<s.size(); i++){
            int j = 0, mn = min<int>(s[i].size(), longest);
            for(; j< mn; j++){
                if(s[i][j] != s[i-1][j])
                    break;
            }
            longest = min(longest, j);
        }
        return s[0].substr(0, longest);
    }
};
