// Author : @AdarshGaur

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(__builtin_popcount(n) != 1) return false;
        if( __builtin_ctz(n) % 2 != 0) return false;
        return true;
    }
};
