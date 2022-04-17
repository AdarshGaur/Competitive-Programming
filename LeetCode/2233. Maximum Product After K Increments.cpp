//Author : @AdarshGaur

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9 +7;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for( ; k>0; k--){
            int u = pq.top();
            pq.pop();
            pq.push(u+1);
        }
        long long p=1;
        while(!pq.empty()){
            p = (p * pq.top()) %mod;
            pq.pop();
        }
        return p;
    }
};
