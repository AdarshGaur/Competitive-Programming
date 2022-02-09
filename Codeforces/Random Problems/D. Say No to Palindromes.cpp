// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m;cin>>n>>m;
	string s;cin>>s;
	int z = (n+2)/3;
	vector<string> p(6);
	for(int i=0; i<z; i++){
		p[0] += "abc";
		p[1] += "acb";
		p[2] += "bca";
		p[3] += "bac";
		p[4] += "cab";
		p[5] += "cba";
	}
	for(int j=0; j<6; j++){
		while((int)p[j].size() > n)p[j].pop_back();
	}
	int pref[6][n+1];
	for(int i=0; i<6; i++){
		pref[i][0] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<6; j++){
			pref[j][i] = pref[j][i-1] + (s[i-1]==p[j][i-1]);
		}
	}
	while(m--){
		int l, r;cin>>l>>r;
		int x = 0;
		for(int i=0; i<6; i++){
			x = max(x, pref[i][r]-pref[i][l-1]);
		}
		cout<<(r-l+1)-x<<endl;
	}
	return 0;
}
