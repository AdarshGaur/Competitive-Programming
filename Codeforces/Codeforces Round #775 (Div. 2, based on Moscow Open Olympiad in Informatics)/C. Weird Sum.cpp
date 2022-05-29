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
int const N = 1e5 + 7;

#define ff first
#define ss second


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	////////////////
	int n, m;
	cin >> n >> m;
	map<int, vector<pii>> color;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int c;
			cin >> c;
			color[c].push_back({i,j});
		}
	}
	int ans = 0;
	for(auto [c, v]: color){
		n = v.size();
		int pref = 0;
		sort(v.begin(), v.end());
		for(int i=1; i<n; i++){
			int dif = abs(v[i].ff - v[i-1].ff);
			dif *= i;
			pref += dif;
			ans += pref;
		}
		pref = 0;
		sort(v.begin(), v.end(), [&](pii a, pii b){
			if(a.ss == b.ss)
				return a.ss < b.ss;
			return a.ss < b.ss;
		});
		for(int i=1; i<n; i++){
			int dif = abs(v[i].ss - v[i-1].ss);
			dif *= i;
			pref += dif;
			ans += pref;
		}
	}
	cout << ans << endl;
	return 0;
}
