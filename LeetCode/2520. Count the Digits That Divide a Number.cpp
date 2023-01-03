// Author: @AdarshGaur

class Solution {
public:
    int countDigits(int num) {
        int x = num, ans = 0;
        while(x){
            int r = x%10;
            x /= 10;
            ans += (num%r == 0 ? 1 : 0);
        }
        return ans;
    }
};
