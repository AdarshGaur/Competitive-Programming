// https://github.com/AdarshGaur/Competitive-Programming
// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;
typedef vector<int> vi;


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
#define debug(...) "Throughout the hells, I alone am the honored one."
#endif

int const INF = 2e18;
int const mod = 998244353;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int dp[n+1][k+1]{};
	dp[0][0] = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			for(int p=1; p<=m and j+p<=k; p++){
				dp[i+1][j+p] = (dp[i+1][j+p] + dp[i][j])%mod;
			}
		}
	}
	int ans{};
	for(int i=1; i<=k; i++){
		ans = (ans + dp[n][i])%mod;
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
