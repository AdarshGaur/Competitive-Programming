// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n, r1=0, r2=0, r0=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		a[i]%=3;
		if(a[i]==1)r1++;
		else if(a[i]==2)r2++;
		else r0++;
	}
	int ans=0;
	int s = r1+r2+r0;
	s/=3;
	for(int i=0; i<2; i++){
		if(r0>s){
			ans += r0-s;
			r1 += r0-s;
			r0=s;
		}
		if(r1>s){
			ans += r1-s;
			r2 += r1-s;
			r1=s;
		}
		if(r2>s){
			ans += r2-s;
			r0 += r2-s;
			r2=s;
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
