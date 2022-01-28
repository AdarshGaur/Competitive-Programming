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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, l;
	cin>>n>>l;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int res=0;
	for(int i=0; i<31; i++){
		int cnt=0;
		for(auto j:a){
			if( j & (1ll<<i) )
				cnt++;
		}
		if((n%2==0 and cnt>=n/2) or (n%2==1 and cnt>n/2)){
			res += (1ll<<i);
		}
	}
	cout<<res<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
