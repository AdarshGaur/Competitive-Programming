// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

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
	string s;
	int n;
	cin >> n >> s;
	int ans = 0;
	for(int i=0; i<n; i++){
		int p=0, m=0, c=0;
		p += (s[i] == '+');
		m += (s[i] == '-');
		char last = s[i];
		for(int j=i+1; j<n; j++){
			if(s[j] == '+') p++;
			else m++;
			if( s[j] == '-' and last == '-' ){
				last = '.';
				c++;
			}else{
				last = s[j];
			}
			if( p + c == m - c*2 or p == m ){
				ans++;
			}else{
				int d = m - p;
				if(d > 0 and (p + d/3) == (m - (d/3)*2)){
					ans += (d/3 <= c ? 1 : 0);
				}
			}
		}
	}
	cout << ans << "\n";
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
