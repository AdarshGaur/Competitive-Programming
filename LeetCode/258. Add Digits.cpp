// Author: @AdarshGaur

class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int t = num;
            num = 0;
            while(t){
                num += t%10;
                t /= 10;
            }
        }
        return num;
    }
};

