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
	int n = 8;
	int a[n];
	int b[] = {2, 3, 5, 7, 11, 13, 17, 19};
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int ans=0, t=1;
	for(int i=0; i<n; i++){
		int x = b[i]-a[i]-1;
		ans += t*x;
		t *= b[i];
	}
	cout<<ans<<endl;
    return 0;
}
