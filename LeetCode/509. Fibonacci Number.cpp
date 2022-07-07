// Author : @AdarshGaur

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int cur = 1, prev = 0;
        for(int i=2; i<=n; i++){
            int temp = cur;
            cur += prev;
            prev = temp;
        }
        return cur;
    }
};
