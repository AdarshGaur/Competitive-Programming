class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> dp(n+2, 0);
		for(int i=0; i<n; i++){
			if(citations[i] >= n)
				dp[n]++;
			else
				dp[citations[i]]++;
		}
		int ans=0;
		for(int i=n; i>=0; i--){
			dp[i] += dp[i+1];
			if(dp[i] >= i){
				ans = i;
				break;
			}
		}
		return ans;
	}
};