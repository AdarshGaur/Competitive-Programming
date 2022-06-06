// Author : @AdarshGaur

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans{};
        int dp[1001][1001];
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
            for(int j=0; j<i; j++){
                int x = mp.find(arr[i]-arr[j]) == mp.end() ? -1 : mp[arr[i]-arr[j]];
                dp[j][i] = (arr[i] - arr[j] < arr[j] && x >=0 ) ? dp[x][j] +1 : 2;
                ans = max(ans, dp[j][i]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
