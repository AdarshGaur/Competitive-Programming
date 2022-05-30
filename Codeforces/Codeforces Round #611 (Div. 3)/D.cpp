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


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m;
	cin >> n >> m;
	int trees[n];
	map<int, bool> taken;
	for(int i=0; i<n; i++){
		cin >> trees[i];
		taken[trees[i]] = true;
	}
	set<pii> options;
	for(int i=0; i<n; i++){
		if(!taken[trees[i]-1]){
			options.insert({1, trees[i]-1});
			taken[trees[i]-1] = true;
		}
		if(!taken[trees[i]+1]){
			options.insert({1, trees[i]+1});
			taken[trees[i]+1] = true;
		}
	}
	vector<int> people;
	int total = 0;
	for(int i=0; i<m; i++){
		pii candidate = *options.begin();
		options.erase(*options.begin());
		auto [moves, pos] = candidate;
		people.push_back(pos);
		total += moves;
		if(!taken[pos-1]){
			options.insert({moves+1, pos-1});
			taken[pos-1] = true;
		}
		if(!taken[pos+1]){
			options.insert({moves+1, pos+1});
			taken[pos+1] = true;
		}
	}
	cout << total << endl;
	for(auto i: people)
		cout << i << " ";
	cout << endl;
	return 0;
}
