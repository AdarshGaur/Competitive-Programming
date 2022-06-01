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

int f(string s){
	int v = 0;
	for(int i=0; i<(int)s.size()-1; i++){
		if(s[i] == '0' and s[i+1] == '1')
			v++;
		else if(s[i] == '1' and s[i+1] == '1')
			v += 11;
		else if(s[i] == '1' and s[i+1] == '0')
			v += 10;
	}
	return v;
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = 0, r = n-1;
	while(l<n and s[l] == '0') l++;
	while(r>=0 and s[r] == '0') r--;
	int one = count(s.begin(), s.end(), '1');
	if(one == 1){
		if(k >= n-1-r){
			swap(s[r], s[n-1]);
		}else if(k >= l){
			swap(s[l], s[0]);
		}
	}else if(one > 1){
		if(k >= n-1-r){
			swap(s[r], s[n-1]);
			k -= n-1-r;
		}
		if(k >= l){
			swap(s[l], s[0]);
			k -= l;
		}
	}
	cout << f(s) << endl;
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
