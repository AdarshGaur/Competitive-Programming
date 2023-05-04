// Author : @AdarshGaur

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x = 1;
        for(auto &i: nums){
            if(i == 0) return 0;
            x *= (i < 0 ? -1 : 1);
        }
        return (x < 0 ? -1 : 1);
    }
};

