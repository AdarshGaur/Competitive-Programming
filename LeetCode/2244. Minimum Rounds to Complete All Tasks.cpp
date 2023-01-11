// Author: @AdarshGaur

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int &i: tasks){
            mp[i]++;
        }
        int rounds = 0;
        for(auto &[n, cnt]: mp){
            if(cnt == 1) return -1;
            rounds += (cnt+2)/3;
        }
        return rounds;
    }
};
