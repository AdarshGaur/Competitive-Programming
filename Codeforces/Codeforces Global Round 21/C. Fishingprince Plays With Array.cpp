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


void solve(){
	int n, m, k;
	cin >> n >> m;
	vector<int> a(n);
	for(int &i: a)
		cin >> i;
	cin >> k;
	vector<int> b(k);
	for(int &i: b)
		cin >> i;
	auto check = [&](vector<int> v){
		vector<pii> extend;
		extend.push_back({-1,-1});
		for(int i=0; i<(int)v.size(); i++){
			int cnt = 1;
			while(v[i] %m == 0){
				v[i] /= m;
				cnt *= m;
			}
			if(extend.back().first == v[i]){
				extend.back().second += cnt;
			}else{
				extend.push_back({v[i], cnt});
			}
		}
		return extend;
	};
	if(check(a) == check(b)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
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