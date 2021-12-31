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
	int n, x, mx=-1;
	cin>>n>>x;
	int cut[n], grow[n], total[n];
	for(int i=0; i<n; i++){
		cin>>cut[i]>>grow[i];
		total[i] = cut[i]-grow[i];
		mx = max(cut[i], mx);
	}
	if(x <= mx){
		cout<<1<<endl;
		return;
	}
	sort(&total[0], &total[n]);
	int profit = total[n-1];
	if(profit <= 0){
		cout<<-1<<endl;
		return;
	}
	x-=mx;
	int ans = (x/profit) + (x%profit != 0);
	cout<<ans+1<<endl;
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
