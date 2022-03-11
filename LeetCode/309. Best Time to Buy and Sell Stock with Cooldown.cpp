// Author : AdarshGaur

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, buy2, sell=0, sell2=0;
        for(int p : prices){
            buy2 = buy;
            buy = max(buy, sell2 - p);
            sell2 = max(sell2, sell);
            sell = max(sell, buy2 + p);
        }
        return sell;
    }
};

