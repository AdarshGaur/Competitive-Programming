// Author : @AdarshGaur

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long maxh = 0, maxv = 0, last = 0;
        for(int& i: horizontalCuts){
            maxh = max(maxh, i - last);
            last = i;
        }
        maxh = max(maxh, h - last);
        last = 0;
        for(int& i: verticalCuts){
            maxv = max(maxv, i - last);
            last = i;
        }
        maxv = max(maxv, w - last);
        return (maxv * maxh)%1000000007;
    }
};
