// Author : AdarshGaur

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for(auto i: nums){
            pq.push(i);
            sum += i;
        }
        int cnt=0;
        auto temp = sum;
        sum /= 2;
        while(temp > sum){
            auto x = pq.top();
            pq.pop();
            temp -= x;
            temp += x/2;
            pq.push(x/2);
            cnt++;
        }
        return cnt;
    }
};
