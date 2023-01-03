// Author: @AdarshGaur

class Solution {
public:
    int minimumPartition(string s, int k) {
        long partition = 1, cur = 0;
        for(int i=0; i<s.size(); i++){
            cur *= 10;
            cur += (s[i]-'0');
            if(cur <= k) continue;
            partition += 1;
            cur = (s[i]-'0');
            if(cur > k) return -1;
        }
        return partition;
    }
};
