// Author: @AdarshGaur

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int pairs[1<<16] = {};
        int n = nums.size(), ans = 0;
        for(int &i: nums){
            for(int &j: nums){
                pairs[i & j]++;
            }
        }
        for(int &i: nums){
            for(int j=0; j<(1<<16); j++){
                if((i & j) == 0){
                    ans += pairs[j];
                }
            }
        }
        return ans;
    }
};
