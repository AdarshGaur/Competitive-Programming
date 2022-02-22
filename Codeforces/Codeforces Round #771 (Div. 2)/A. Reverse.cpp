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
	int n;cin>>n;
	int p[n+1];
	for(int i=1; i<=n; i++){
		cin>>p[i];
	}
	p[0]=0;
	int ind = n+1, end=n+1;
	for(int i=1; i<=n; i++){
		if(p[i]!=i){
			ind = i;
		}
		if(ind!=n+1){
			for(int j=i+1; j<=n; j++){
				if(p[j]==i){
					end = j;
					break;
				}
				if(end!=n+1)break;
			}
			break;
		}
	}
	for(int i=1; i<ind; i++){
		cout<<p[i]<<" ";
	}
	if(end!=n+1){
		for(int i=end; i>=ind; i--){
			cout<<p[i]<<" ";
		}
		for(int i=end+1; i<=n; i++){
			cout<<p[i]<<" ";
		}
	}
	cout<<endl;
	
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
