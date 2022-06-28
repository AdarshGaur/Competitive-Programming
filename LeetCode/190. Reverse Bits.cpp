// Author : @AdarshGaur

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i=0, j=31; i<=j; i++, j--){
            if(n & (1 << i)) ans |= (1<<j);
            if(n & (1 << j)) ans |= (1<<i);
        }
        return ans;
    }
};
