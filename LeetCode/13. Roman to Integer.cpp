// Author : @AdarshGaur

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> h = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = h[s.back()];
        for(int i=s.size()-2; i>=0; i--){
            if(h[s[i]] < h[s[i+1]])
                ans -= h[s[i]];
            else
                ans += h[s[i]];
        }
        return ans;
    }
};
