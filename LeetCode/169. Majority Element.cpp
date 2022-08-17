// Author : @AdarshGaur

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = (1e9 +7) * -1, xc = 0;
        for(int i: nums){
            if(xc == 0)
                x = i;
            xc += (x == i ? 1 : -1);
        }
        return x;
    }
};
