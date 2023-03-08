// Author: @AdarshGaur

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long minimumTrips = 1e18;
        long long lo = 0, hi = 1e14;
        while(lo <= hi){
            auto mid = lo + (hi - lo)/2;
            long long taken = 0;
            for(auto &i: time){
                taken += mid/i;
            }
            if(taken >= totalTrips){
                hi = mid -1;
                minimumTrips = mid;
            }else{
                lo = mid +1;
            }
        }
        return minimumTrips;
    }
};

