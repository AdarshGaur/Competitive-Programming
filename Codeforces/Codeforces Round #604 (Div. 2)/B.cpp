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
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n;cin>>n;
	int pos[n+1]={0};
	for(int i=0; i<n; i++){
		int x;cin>>x;
		pos[x]=i;
	}
	string ans;
	int mn=n, mx=0;
	for(int i=1; i<=n; i++){
		mn = min(mn, pos[i]);
		mx = max(mx, pos[i]);
		if(mx-mn+1 != i){
			ans += "0";
		}else{
			ans += "1";
		}
	}
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
