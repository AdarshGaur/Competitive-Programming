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
	int n, mx=0;
	cin>>n;
	vi a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
		mx = max(a[i], mx);
	}
	if(mx!= a[0] and mx!=a[n-1]){
		cout<<-1<<endl;
		return;
	}
	reverse(&a[0], &a[n]);
	for(auto i: a){
		cout<<i<<" ";
	}
	cout<<endl;	
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