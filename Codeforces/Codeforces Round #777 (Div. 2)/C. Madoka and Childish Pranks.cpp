// Author : Adarsh Gaur 

// #define NDEBUG
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
// int const N = 2e5 + 7;


void solve(){
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	if(s[0][0] == '1'){
		cout << -1 << endl;
		return ;
	}
	vector<tuple<int, int, int, int>> ans;
	vector<string> mt(n, string(m, '0'));
	for(int i=n-1; i>0; i--){
		for(int j=m-1; j>0; j--){
			if(mt[i][j] != s[i][j]){
				if(s[i][j] == '0'){
					ans.push_back({i, j, i, j});
				}else{
					ans.push_back({i, j-1, i, j});
					mt[i][j-1] = '0';
				}
				mt[i][j] = s[i][j];
			}
		}
		if(mt[i][0] != s[i][0]){
			if(s[i][0] == '0'){
				ans.push_back({i, 0, i, 0});
			}else{
				ans.push_back({i-1, 0, i, 0});
				mt[i-1][0] = '0';
			}
			mt[i][0] = s[i][0];
		}
	}
	for(int j=m-1; j>0; j--){
		if(mt[0][j] != s[0][j]){
			if(s[0][j] == '0'){
				ans.push_back({0, j, 0, j});
			}else{
				ans.push_back({0, j-1, 0, j});
				mt[0][j-1] = '0';
			}
			mt[0][j] = s[0][j];
		}
	}
	cout << ans.size() << endl;
	for(auto [i, j, k, l] : ans){
		cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << endl;
	}
}

int32_t main()
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
