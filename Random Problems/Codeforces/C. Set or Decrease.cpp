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
#define max(a,b) max<int>(a,b)
#define ii(x) (int)(x)

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;

int flooor(int a, int b){
	int ret = a/b;
	while(ret * b > a)ret--;
	return ret;
}

void solve(){
	int n, k;cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int pref[n]={0};
	for(int i=0; i<n; i++){
		if(i>0)pref[i] = pref[i-1];
		pref[i] += a[i];
	}
	if(pref[n-1] <= k){
		cout<<0<<endl;
		return ;
	}
	int ans=INF;
	for(int i=1; i<=n; i++){
		int d = (k-pref[n-i]+a[0]);
		int x = flooor(d,i);
		x = max(a[0]-x, 0);
		ans = min(ans, x+i-1);
	}
	cout<<ans<<endl;
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
