// Author : @AdarshGaur

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setbits = 0;
        while(num2){
            if(num2&1) setbits++;
            num2 >>= 1;
        }
        
        int ans = 0;
        for(int i=30; i>=0; i--){
            if((num1 & (1<<i)) and setbits){
                ans |= (1<<i);
                setbits--;
            }
        }
        
        int j = -1;
        while(setbits){
            j++;
            if(ans & (1<<j)) continue;
            ans |= (1<<j);
            setbits--;
        }
        return ans;
    }
};
