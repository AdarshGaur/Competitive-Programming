// Author : @AdarshGaur

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int c = a&b;
            a ^= b;
            b = unsigned(c) << 1;
        }
        return a;
    }
};
