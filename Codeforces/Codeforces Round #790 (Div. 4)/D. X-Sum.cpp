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
#define debug(...) "..."
#endif

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

int n, m;
vector<vi> a;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

int fun(int x, int y){
	int d = a[x][y];
	for(int k=0; k<4; k++){
		for(int i=x+dx[k], j=y+dy[k]; i>=0 && j>=0 && i<n && j<m; i+=dx[k], j+=dy[k]){
			d += a[i][j];
		}
	}
	return d;
}

void solve(){
	cin >> n >> m;
	a.clear();
	a.resize(n, vi(m, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int d = fun(i, j);
			ans = max(ans, d);
		}
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
