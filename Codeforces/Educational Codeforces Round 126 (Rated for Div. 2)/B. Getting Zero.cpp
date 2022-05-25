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
#define debug(...) "Throughout the hells, I alone am the honored one."
#endif

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
int const N = 32768;
int dp[N];

int findMin(int n){
	if(dp[n] != INF)
		return dp[n];
	int k=0, a = n;
	while(a%2 == 0)
		a/=2, k++;
	dp[n] = min(15-k, findMin((n+1)%N) +1);
	return dp[n];
}

void pre(){
	fill(dp, dp+N, INF);
	dp[0] = 0;
	dp[N-1] = 1;
	for(int i=14; i>=0; i--)
		dp[(1<<i)] = 15-i;
	for(int i=0; i<N; i++)
		findMin(i);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	pre();
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		cout << dp[a] << " ";
	}
	return 0;
}
