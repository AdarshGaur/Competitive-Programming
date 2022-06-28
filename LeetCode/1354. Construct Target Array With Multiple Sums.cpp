// Author : @AdarshGaur

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        long long sum = accumulate(target.begin(), target.end(), 0ll);
        priority_queue<int> pq(target.begin(), target.end());
        while(pq.top() > sum/2 and sum > 1){
            int tp = pq.top();
            pq.pop();
            sum -= tp;
            if(sum <= 1)
                return sum;
            pq.push(tp % sum);
            sum += (tp % sum);
        }
        return sum == target.size();
    }
};
