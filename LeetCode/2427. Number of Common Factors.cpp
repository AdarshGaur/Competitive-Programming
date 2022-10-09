// Author : @AdarshGaur

class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 1;
        for(int i=2; i<=min(a, b); i++)
            if(a % i == 0 and b % i == 0)
                ans++;
        return ans;
    }
};
