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
	int n;cin>>n;
	vector<pii> a;
	for(int i=0; i<n; i++){
		int x;cin>>x;
		a.push_back({x,i});
	}
	sort(&a[0], &a[n]);
	int pref[n];
	pref[0]=a[0].ff;
	for(int i=1; i<n; i++){
		pref[i] = pref[i-1] + a[i].ff;
	}
	int ans=a[0].ff;
	for(int i=0; i<n-1; i++){
		if(pref[i] < a[i+1].ff){
			ans = a[i+1].ff;
		}
	}
	vi res;
	for(int i=0; i<n; i++){
		if(a[i].ff >= ans){
			res.push_back(a[i].ss);
		}
	}
	cout<<res.size()<<endl;
	sort(res.begin(), res.end());
	for(auto i : res){
		cout<<i+1<<" ";
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
