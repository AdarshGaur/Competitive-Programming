// Author : @AdarshGaur

class Solution {
public:
    int dist(int x1, int y1, int x2, int y2, int r){
        return r >= sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(auto a : circles){
            for(int i = a[0]-a[2]; i <= a[0]+a[2]; i++){
                for(int j = a[1]-a[2]; j<=a[1]+a[2]; j++){
                    if(dist(i, j, a[0], a[1], a[2]))
                        s.insert({i,j});
                }
            }
        }
        return s.size();
    }
};
