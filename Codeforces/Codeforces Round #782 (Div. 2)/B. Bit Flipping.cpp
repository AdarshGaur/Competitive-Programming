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


void solve(){
	int n, k, flip{};
	cin >> n >> k;
	string s;
	cin >> s;
	int freq[n]{};
	for(int i=0; i<n and k>0; i++){
		int b = (s[i]-'0')^flip;
		if((b == 1 and k%2) or (b==0 and k%2==0)){
			flip ^= 1;
			k -= 1;
			freq[i]++;
			s[i] = ( s[i] == '0' ? '1' : '0');
		}
	}
	if(k>0){
		freq[n-1] += k;
		k %= 2;
		if(k) s[n-1] = (s[n-1] == '0' ? '1' : '0');
		flip ^= k;
	}
	if(flip){
		for(auto &i : s){
			i = (i == '0' ? '1' : '0');
		}
	}
	cout << s << endl;
	for(auto i : freq)
		cout << i << " ";
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
