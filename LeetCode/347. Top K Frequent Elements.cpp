// Author : @AdarshGaur

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int, int> freq;
        for(auto i: nums) freq[i]++;
        for(auto [u,v]: freq) pq.push({v, u});
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
