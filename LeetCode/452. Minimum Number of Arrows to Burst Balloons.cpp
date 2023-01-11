// Author: @AdarshGaur

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        long arrows = 0, last = -1e12;
        for(auto &a: points){
            if(a[0] > last){
                last = a[1];
                arrows++;
            }
        }
        return arrows;
    }
};
