// Author : @AdarshGaur

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(int &i: arr)
            mp[i]++;
        priority_queue<int> pq;
        for(auto &[key, freq]: mp)
            pq.push(freq);
        int cnt = 0, sum = 0;
        while(sum < arr.size()/2){
            sum += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};
