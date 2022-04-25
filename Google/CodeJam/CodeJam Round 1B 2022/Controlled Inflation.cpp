// https://github.com/AdarshGaur/Competitive-Programming
// Author : @AdarshGaur


#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;
typedef vector<int> vi;


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
#define debug(...) "Throughout the hells, I alone am the honored one."
#endif

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, p;
	cin >> n >> p;
	vector<pii> a;
	for(int i=0; i<n; i++){
		int mn = INF, mx = 0, x;
		for(int j=0; j<p; j++){
			cin >> x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
		a.push_back({mn, mx});
	}
	vi last{0,0}, dp{0,0};
	for(auto &[u, v] : a){
		int p1 = INF, p2 = INF;
		for(int i=0; i<2; i++){
			p1 = min(p1, dp[i] + abs(last[i]-u) + abs(u-v));
			p2 = min(p2, dp[i] + abs(last[i]-v) + abs(u-v));
		}
		dp = {p1, p2};
		last = {v, u};
	}
	cout << min(dp[0], dp[1]) << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
