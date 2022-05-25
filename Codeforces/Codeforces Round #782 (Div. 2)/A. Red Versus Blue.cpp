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

string f(int r, int b, int mx){
	if(b == 0)
		return string(r, 'R');
	if(mx == 1){
		string s = "";
		while(b--){
			s += "RB";
			r--;
		}
		assert(r>=0);
		s += string(r, 'R');
		return s;
	}
	if(r-mx < b-1)
		return f(r, b, mx-1);
	string s(mx, 'R');
	s += 'B';
	return s + f(r-mx, b-1, mx);
}

void solve(){
	int n, r, b;
	cin >> n >> r >> b;
	int mx = r/(b+1);
	if(b*mx + mx < r) mx++;
	string s = f(r, b, mx);
	debug(s.size(), mx);
	cout << s << endl;
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
