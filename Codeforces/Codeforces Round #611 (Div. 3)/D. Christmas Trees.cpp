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
	map<int,int> mp, removed;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		mp[x] = 0;
	}
	vector<pii> people; // {position , distance }
	while((int)people.size() < m){
		auto t = mp;
		for(auto &[u, v]: mp){
			if(t.find(u-1) == t.end() and removed.find(u-1) == removed.end()){
				t[u-1] = v+1;
				people.push_back({u-1, v+1});
			}
			if(t.find(u+1) == t.end() and removed.find(u+1) == removed.end()){
				t[u+1] = v+1;
				people.push_back({u+1, v+1});
			}
			t.erase(u);
			removed[u]++;
		}
		mp = t;
	}
	int sum = 0;
	for(int i=0; i<m; i++){
		sum += people[i].second;
	}
	cout << sum << endl;
	for(int i=0; i<m; i++)
		cout << people[i].first << " \n"[i == m-1];
	return 0;
}
