// Author : AdarshGaur

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int lastmin=p[0], profit2=-p[0], profit1=0;
        int n = p.size(), ans=0;
        for(int i=1; i<n; i++){
            int first = p[i]-lastmin;
            int sec = p[i] + profit2;
            ans = max({ans, first, sec});
            lastmin = min(lastmin, p[i]);
            profit2 = max(profit2, profit1-p[i]);
            profit1 = max(profit1, first);
        }
        return ans;
    }
};
