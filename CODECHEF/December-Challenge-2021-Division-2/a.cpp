// Author : Adarsh Gaur 

// Problem Name : List of Lists
// Problem url : https://www.codechef.com/DEC21B/problems/LISTLIST

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

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
	int n;cin>>n;
	int a[n];
	map<int,int> mp;
	for(int i=0; i<n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	int mx = 0, ans=0;
	for(auto [u,v]:mp)mx = max(mx, v);
	if(n>1 and mx<2){
		ans=-1;
	}else if(n==mx){
		ans=0;
	}else{
		ans = n-mx+1;
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
