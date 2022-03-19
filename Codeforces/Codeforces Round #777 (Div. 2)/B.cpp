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
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m-1; j++){
			int p = (s[i][j]-'0') + (s[i+1][j]-'0') + 
					(s[i][j+1]-'0') + (s[i+1][j+1]-'0');
			if( p == 3){
				cout << "NO" << endl;
				return ;
			}
		}
	}
	cout << "YES" << endl;
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
