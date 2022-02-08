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
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, k;cin>>n>>k;
	int mt[n][k];
	int od=1, ev=2;
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			if(i&1){
				mt[i][j] = ev;
				ev+=2;
			}else{
				mt[i][j] = od;
				od+=2;
			}
		}
	}
	if(mt[n-1][k-1] == n*k){
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<k; j++){
				cout<<mt[i][j]<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<"NO"<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
