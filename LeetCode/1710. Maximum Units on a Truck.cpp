// Author : @AdarshGaur

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });
        int ans = 0;
        for(auto &v: boxTypes){
            int space = min(truckSize, v[0]);
            truckSize -= space;
            ans += space * v[1];
            if(!truckSize) break;
        }
        return ans;
    }
};
