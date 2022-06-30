// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;


// Source : https://codeforces.com/blog/entry/76087
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > (int)0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef cicada
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

int const INF = 2e18;
// int const mod = 1e9 +7;
int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int dp[n][m+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=m; i++)
		dp[0][i] = 1;
	vector<int> prefSum(m+1);
	iota(prefSum.begin(), prefSum.end(), 0);
	for(int i=1; i<n; i++){
		for(int j=1; j<=m; j++){
			int x = max<int>(0, j - k);
			int sum1 = prefSum[x];
			int sum2{};
			if(j + k <= m){
				sum2 = prefSum[m] - prefSum[j+k-1];
			}
			if(k == 0){
				sum2 = prefSum[m], sum1 = 0;
			}
			dp[i][j] = (sum1 + sum2)%mod;
		}
		for(int j=1; j<=m; j++){
			prefSum[j] = prefSum[j-1] + dp[i][j];
		}
	}
	int ans{};
	for(int i=1; i<=m; i++){
		ans += dp[n-1][i];
		ans %= mod;
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
