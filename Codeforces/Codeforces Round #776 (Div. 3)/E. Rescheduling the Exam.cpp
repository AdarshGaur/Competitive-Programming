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
#define debug(...) "Hard work betrays none but dreams betray many."
#endif

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, d;
	cin >> n >> d;
	vector<int> a(n), t(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
		a[i]--;
		t[i] = a[i] - (i == 0 ? 0 : a[i-1] +1);
	}
	int id = min_element(t.begin(), t.end()) - t.begin();
	int ans{};
	for(int j: {id, id-1}){
		if(j < 0) continue;
		int mx=0, mn=INF, last=-1;
		for(int i=0; i<n; i++){
			if(i == j) continue;
			mx = max(mx, a[i] - last -1);
			mn = min(mn, a[i] - last -1);
			last = a[i];
		}
		int res = max((mx-1)/2, d - 2 - last);
		ans = max(ans, min(mn, res));
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
