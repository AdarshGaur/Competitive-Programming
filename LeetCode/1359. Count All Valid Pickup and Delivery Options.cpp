// Author : AdarshGaur

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 +7;
        long res = 1;
        for(int i=2; i<=n; i++){
            // ways to arrange the pickups 1 * 2 * 3 * ... * (n-1) * n
            res = res * i;
            //ways to insert the deliveries after its pickup
            // 1 * 3 * 5 * ... * (2*(n-1) -1) * (2*n-1)
            res = res * (2*i -1);
            res = res % mod;
        }
        return res;
    }
};
