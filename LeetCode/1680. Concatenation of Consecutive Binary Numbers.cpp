// Author : @AdarshGaur

class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, p = 1, mod = 1e9 +7;
        for(int i = n; i > 0; i--){
            int j = i;
            while(j > 0){
                if(j&1){
                    ans = (ans + p) % mod;
                }
                j >>= 1;
                p = (p * 2) % mod;
            }
        }
        return ans;
    }
};
