// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints DUMBASS
const int mod = 1e9 +7;
//const int mod = 998244353;

int ten[11];

void init(){
	ten[0]=1;
	for(int i=1; i<11; i++){
		ten[i] = ten[i-1] * 10;
	}
}

void solve(){
	int n, k;cin>>n>>k;k++;
	int a[n];
	for(int i=0; i<n; i++)cin>>a[i];
	int ans=0;
	//a.push_back();
	for(int i=1; k and i<n; i++){
		int x = (ten[a[i]] - ten[a[i-1]])/ten[a[i-1]];
		x = min(x, k);
		k-=x;
		ans += x*ten[a[i-1]];
	}
	if(k>0)ans += k*ten[a[n-1]];
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	init();
    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
