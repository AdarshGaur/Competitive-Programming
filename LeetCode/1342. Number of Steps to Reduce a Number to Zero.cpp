// Author : @AdarshGaur

class Solution {
public:
    int numberOfSteps(int n) {
        if(n == 0) return 0;
        int ans = 0;
        while(n){
            if(n&1)
                ans++;
            ans++;
            n >>= 1;
        }
        return ans-1;
    }
};
