// Author : @AdarshGaur

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int curTime = 0;
        priority_queue<int> pq;
        for(auto &c: courses){
            curTime += c[0];
            pq.push(c[0]);
            if(curTime > c[1]){
                curTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
