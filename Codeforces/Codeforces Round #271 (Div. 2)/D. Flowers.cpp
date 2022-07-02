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
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 1e5 + 7;

int dp[N];

void pre(int k){
	dp[0] = 1;
	for(int i=1; i<N; i++){
		dp[i] = dp[i-1];
		if(i >= k)
			dp[i] = (dp[i-1] + dp[i-k])%mod;
	}
	for(int i=1; i<N; i++){
		dp[i] += dp[i-1];
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int t, k;
	cin >> t >> k;
	pre(k);
	for(int i=0; i<t; i++){
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a-1] + mod) % mod << endl;
	}
	return 0;
}