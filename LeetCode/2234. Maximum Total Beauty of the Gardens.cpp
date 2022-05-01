// Author : @AdarshGaur

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long nf, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        long long n = flowers.size(), ans = 0;
        if(flowers[0] >= target) return full * n;
        auto p1 = n-1;
        for( ; p1 >= 0; p1--){
            if(target - flowers[p1] > nf) break;
            nf -= max(0, target-flowers[p1]);
        }
        if(p1 < 0)
            return max((long long)full * n, (long long)full*(n-1) + (long long)partial*(target-1));
        for(long long mn = flowers[0], p2 = 0, sum=0; mn < target; ){
            while(p2 <= p1 and flowers[p2] <= mn)
                sum += flowers[p2++];
            long long need = (p2) * mn - sum;
            if(need > nf){
                p1++;
                if(p1 == n) break;
                nf += max(0, target - flowers[p1]);
            }else{
                ans = max(ans, mn*partial + (n-1-p1)*full);
                mn++;
            }
        }
        return ans;
    }
};
