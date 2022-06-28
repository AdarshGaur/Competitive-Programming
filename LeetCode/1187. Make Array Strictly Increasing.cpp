// Author : @AdarshGaur

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        int n = arr1.size(), m = arr2.size();
        vector<vector<int>> dp(m+1, vector<int>(n, INT_MAX));
        dp[0][0] = INT_MIN;
        for(int i=0; i<=m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j] == INT_MAX) continue;
                auto it = upper_bound(arr2.begin(), arr2.end(), dp[i][j]);
                if(dp[i][j] >= arr1[j]){
                    if( it != arr2.end()){
                        if(j+1 == arr1.size()) return i+1;
                        dp[i+1][j+1] = min(dp[i+1][j+1], *it);
                    }
                }else{
                    if(j+1 == arr1.size()) return i;
                    dp[i][j+1] = min(dp[i][j+1], arr1[j]);
                    if( it != arr2.end() and *it < arr1[j])
                        dp[i+1][j+1] = min(dp[i+1][j+1], *it);
                }
            }
        }
        return -1;
    }
};
