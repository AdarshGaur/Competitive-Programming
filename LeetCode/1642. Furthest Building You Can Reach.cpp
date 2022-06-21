// Author : @AdarshGaur

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int, greater<int>> s;
        int indx{};
        for( ;indx < heights.size()-1; indx++){
            int dif = heights[indx+1] - heights[indx];
            if(dif <= 0 ) continue;
            if(ladders>0 or bricks >= dif){
                s.insert(dif);
                bricks -= dif;
                if(bricks < 0){
                    bricks += *s.begin();
                    s.erase(s.begin());
                    ladders--;
                }
            }else return indx;
        }
        return indx;
    }
};
