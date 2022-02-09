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
// int const mod = 998244353;
// int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)cin>>b[i];
	int pref[n+1]={0};
	for(int i=0; i<n; i++){
		pref[i+1] = pref[i] + (a[i]*b[i]);
	}
	int ans = pref[n], total = pref[n];
	for(int i=0; i<n; i++){
		int cur=a[i]*b[i];
		for(int l=i-1, r=i+1; l>=0 and r<n; l--, r++){
			cur += a[r]*b[l];
			cur += a[l]*b[r];
			ans = max(ans, cur + pref[l]+total-pref[r+1]);
		}
		cur=0;
		for(int l=i, r=i+1; l>=0 and r<n; l--, r++){
			cur += a[r]*b[l];
			cur += b[r]*a[l];
			ans = max(ans, cur + pref[l]+total-pref[r+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
