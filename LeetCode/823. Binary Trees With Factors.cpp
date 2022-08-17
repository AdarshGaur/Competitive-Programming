// Author : @AdarshGaur

class Solution {
public:
    int mod = 1e9 +7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,int> mp;
        sort(arr.begin(), arr.end());
        vector<long> dp(arr.size(), 1);
        for(int i=0; i<arr.size(); i++){
            for(int j = i-1; j>=0; j--){
                int x = arr[i] / arr[j];
                if(arr[i] % arr[j] == 0 and mp.count(x)){
                    dp[i] = (dp[i] + dp[j] * dp[ mp[x] ]) %mod;
                }
            }
            mp[ arr[i] ] = i;
        }
        return accumulate(dp.begin(), dp.end(), 0ll) % mod;
    }
};
