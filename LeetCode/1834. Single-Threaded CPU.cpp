// Author: @AdarshGaur

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<tuple<int,int,int>> tsks;
        for(int i=0; i<tasks.size(); i++){
            tsks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(tsks.begin(), tsks.end());
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int curTime = 0;
        for(auto &[enqueTime, processingTime, indx] : tsks){
            while(!pq.empty() and curTime < enqueTime){
                auto p = pq.top();
                pq.pop();
                int t = -p.first, ind = - p.second;
                curTime += t;
                ans.push_back(ind);
            }
            curTime = max(curTime, enqueTime);
            pq.push({-processingTime, -indx});
        }
        while(!pq.empty()){
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
