// Author : @AdarshGaur

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto &v: matrix){
            for(int &i: v){
                pq.push(i);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
