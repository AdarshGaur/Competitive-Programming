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
	int n;cin>>n;
	int a[n];
	map<int,int> mp;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int mn = INF;
	for(int i=0; i<n; i++){
		if(mp.count(a[i])==0){
			mp[a[i]]=i;
		}else{
			mn = min(mn, i-mp[a[i]]+1);
			mp[a[i]] = i;
		}
	}
	if(mn == INF)mn=-1;
	cout<<mn<<endl;
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
