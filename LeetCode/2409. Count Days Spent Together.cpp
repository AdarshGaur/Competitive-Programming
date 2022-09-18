// Author : @AdarshGaur

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1; i<=12; i++)
            days[i] += days[i-1];
        
        auto f = [&](string &s){
            return days[stoi(s.substr(0,2)) -1] + stoi(s.substr(3, 2));
        };
        
        int arrive = max(f(arriveAlice), f(arriveBob));
        int leave = min(f(leaveAlice), f(leaveBob));
        return max(0, leave-arrive+1);
    }
};
