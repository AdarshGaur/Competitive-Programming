// Author : AdarshGaur

class Solution {
public:
    double average(vector<int>& salary) {
        int mn = 1e6 +7, mx = 999;
        double sum = 0;
        for(auto &i: salary){
            sum += i;
            mn = min(mn, i);
            mx = max(mx, i);
        }
        sum -= (mn + mx);
        return sum/(salary.size() - 2);
    }
};

