// Author: @AdarshGaur

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long minimum_eating_speed = 1e12;
        long lo = 1, hi = 1e12;
        while(lo <= hi){
            long m = lo + (hi - lo)/2;
            long count = 0;
            for(auto &i: piles){
                count += (i+m-1)/m;
            }
            if(count <= h){
                minimum_eating_speed = m;
                hi = m -1;
            }else{
                lo = m +1;
            }
        }
        return minimum_eating_speed;
    }
};
