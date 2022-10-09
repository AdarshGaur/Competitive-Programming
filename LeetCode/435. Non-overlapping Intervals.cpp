// Author : @AdarshGaur

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int next = intervals[n-1][0], total = 1;
        for(int i= n - 2; i>=0; i--){
            if(intervals[i][1] <= next){
                next = intervals[i][0];
                total++;
            }
        }
        return intervals.size() - total;
    }
};
