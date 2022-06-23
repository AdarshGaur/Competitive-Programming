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
// int const N = 2e5 + 7;

string ans;
vector<vector<int>> g(26);
vector<int> vis(26, 0);


bool dfs(int cur){
	if(vis[cur] == 2) return true;
	if(vis[cur] == 1) return false;
	vis[cur] = 1;
	for(auto v: g[cur]){
		if(!dfs(v))
			return false;
	}
	vis[cur] = 2;
	ans.push_back(cur+'a');
	return true;
}

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(string &i: s)
		cin >> i;
	for(int i=1; i<n; i++){
		int m = min<int>(s[i].size(), s[i-1].size());
		int j=0;
		for(; j<m; j++){
			if(s[i][j] != s[i-1][j]){
				int a = s[i-1][j] - 'a';
				int b = s[i][j] - 'a';
				g[b].push_back(a);
				break;
			}
		}
		if(j == m and m == (int)s[i].size()){
			cout << "Impossible" << endl;
			return;
		}
	}
	for(int i=0; i<26; i++){
		if(!vis[i] and !dfs(i)){
			cout << "Impossible" << endl;
			return ;
		}
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
