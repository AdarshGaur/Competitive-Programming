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
	int n;cin>>n;
	int a[n];
	for(auto &i :a)cin>>i;
	int black=0, white=0;
	for(int i=0; i<n; i++){
		black += a[i]/2;
		white += a[i]/2;
		if(i&1){
			black += a[i]%2;
		}else{
			white += a[i]%2;
		}
	}
	cout<<min(black, white)<<endl;
	return 0;
}
