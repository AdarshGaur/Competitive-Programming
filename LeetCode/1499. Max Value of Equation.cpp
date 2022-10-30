// Author : @AdarshGaur

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size(), ans = INT_MIN;
        deque<int> dq;
        for(int i=0; i<n; i++){
            while(!dq.empty() and points[i][0] - points[dq.back()][0] > k)
                dq.pop_back();
            if(!dq.empty())
                ans = max(ans, points[i][0] + points[i][1] + points[dq.back()][1] - points[dq.back()][0]);
            while(!dq.empty() and points[i][0] - points[i][1] < points[dq.front()][0] - points[dq.front()][1])
                dq.pop_front();
            dq.push_front(i);
        }
        return ans;
    }
};
