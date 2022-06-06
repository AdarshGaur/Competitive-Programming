// Author : @AdarshGaur

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(auto c='1'; c <= n+'0'; c++)
            s += c;
        k--;
        while(k--){
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};
