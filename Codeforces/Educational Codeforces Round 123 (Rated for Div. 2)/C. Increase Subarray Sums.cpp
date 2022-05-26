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
	int n, x, mx=0;
	cin >> n >> x;
	int a[n], v[n+1];
	for(int &i: a)
		cin >> i;
	fill(v, v+n+1, -INF);
	v[0] = 0;
	for(int i=0; i<n; i++){
		int s = 0;
		for(int j=i; j<n; j++){
			s += a[j];
			v[j-i+1] = max(v[j-i+1], s);
			mx = max(mx, s);
		}
	}
	cout << mx << " ";
	for(int k=1; k<=n; k++){
		mx = 0;
		int add = k*x;
		// subarrays with length more than or equal to k
		for(int i = k; i<=n; i++){
			mx = max(mx, v[i]+add);
		}
		// subarrays with length less than k
		for(int i = k-1; i>=0; i--){
			add = i*x;
			mx = max(mx, v[i]+add);
		}
		cout << mx << " ";
	}
	cout << endl;
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
