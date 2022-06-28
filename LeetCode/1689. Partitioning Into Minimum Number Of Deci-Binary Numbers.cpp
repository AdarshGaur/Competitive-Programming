// Author : @AdarshGaur

class Solution {
public:
    int minPartitions(string s) {
        int maxNum = 0;
        for(auto i: s){
            maxNum = max(maxNum, i-'0');
        }
        return maxNum;
    }
};
