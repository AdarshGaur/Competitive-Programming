// Author: @AdarshGaur

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        long radius = 1e9, lo = 0, hi = 1e9;
        while(lo <= hi){
            auto m = lo + (hi-lo)/2;
            int j = 0, pos = 1;
            for(int i=0; i<houses.size(); i++){
                if(j >= heaters.size() or heaters[j] -m > houses[i]){
                    pos = 0;
                    break;
                }
                if(heaters[j] + m < houses[i]){
                    j++, i--;
                }
            }
            if(pos){
                radius = m;
                hi = m-1;
            }else{
                lo = m + 1;
            }
        }
        return radius;
    }
};

