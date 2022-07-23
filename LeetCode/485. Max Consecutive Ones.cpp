// Author : @AdarshGaur

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt{}, ans{};
        for(int &i: nums){
            if(i == 1){
                cnt++;
                ans = max(ans, cnt);
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
};
