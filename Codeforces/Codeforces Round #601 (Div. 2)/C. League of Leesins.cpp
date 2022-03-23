// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

void solve(){
	int n; cin >> n;
	vi freq(n+1, 0);
	map<pii, vi> mp;
	for(int i=0; i<n-2; i++){
		int a, b, c;
		cin >> a >> b >> c;
		mp[{a, b}].emplace_back(c);
		mp[{a, c}].emplace_back(b);
		mp[{b, c}].emplace_back(a);
		mp[{b, a}].emplace_back(c);
		mp[{c, a}].emplace_back(b);
		mp[{c, b}].emplace_back(a);
		freq[a]++, freq[b]++, freq[c]++;
	}
	int j=0, k =0;
	for(auto i=1; i<=n; i++){
		if(freq[i] == 1){
			j = i;
			break;
		}
	}
	for(int i=1; i<=n; i++){
		if(freq[i] == 2 and mp.count({j,i})){
			k = i;
			break;
		}
	}
	vi p(2, j);
	p[1] = k;
	for(int i=2; i<n; i++){
		auto v = mp[{j, k}];
		freq[j] = -1;
		j = k;
		if(freq[v[0]] != -1){
			p.push_back(v[0]);
			k = v[0];
		}else{
			k = v[1];
			p.push_back(v[1]);
		}
	}
	for(auto i : p){
		cout << i << " ";
	}
	cout << endl;
}

int32_t main()
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
