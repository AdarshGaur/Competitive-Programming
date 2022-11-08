// Author : @AdarshGaur

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], maxi=0, ans=0;
        for(int i=1; i<prices.size(); i++){
            if(mini>prices[i]){
                ans = max(ans,maxi-mini);
                mini = prices[i];
                maxi = 0;
            }else{
                maxi = max(maxi, prices[i]);
            }
        }
        ans = max(ans, maxi-mini);
        return ans;
    }
};
