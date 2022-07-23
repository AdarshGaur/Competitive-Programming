// Author : @AdarshGaur

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for(auto &i: nums){
            if(m1 <= i){
                if(m1 == i) continue;
                swap(m3, m2);
                swap(m2, m1);
                m1 = i;
            }else if(m2 <= i){
                if(m2 == i) continue;
                swap(m2, m3);
                m2 = i;
            }else if(m3 < i){
                m3 = i;
            }
        }
        return (m3 == LONG_MIN ? m1 : m3);
    }
};
