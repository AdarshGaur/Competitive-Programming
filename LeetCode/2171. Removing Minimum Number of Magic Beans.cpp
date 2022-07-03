// Author : @AdarshGaur

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0ll), ans = 1e12, n = beans.size();
        for(int i=0; i<n; i++){
            ans = min(ans, total - beans[i]*(n-i));
        }
        return ans;
    }
};
