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


void solve(){
	int n, q;cin>>n>>q;
	pii a[n];
	for(int i=0; i<n; i++){
		cin>>a[i].ff;
		a[i].ss = i+1;
	}
	map<pii,int> mp;
	sort(a, a+n);
	for(int i=0; i<n;){
		int x = i;
		while(x<n and a[x].ff == a[i].ff){
			x++;
			mp[{a[i].ff, x-i}] = a[x-1].ss;
		}
		i=x;
	}
	while(q--){
		int x, k;cin>>x>>k;
		if(mp.count({x,k})!=0){
			cout<<mp[{x,k}]<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}
