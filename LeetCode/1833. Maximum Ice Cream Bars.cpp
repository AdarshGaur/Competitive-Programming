// Author: @AdarshGaur

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int cnt = 0;
        for(int &i: costs){
            coins -= i;
            if(coins < 0)
                return cnt;
            cnt++;
        }
        return cnt;
    }
};
