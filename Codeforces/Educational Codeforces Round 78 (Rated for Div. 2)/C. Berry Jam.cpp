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


int solve(){
	int n;cin>>n;
	int a[2*n];
	for(int i=0; i<2*n; i++){
		cin>>a[i];
	}
	int dif=0;
	for(int i=n; i<2*n; i++){
		if(a[i]==1)dif++;
		else dif--;
	}
	// 1 = +, 2 = -
	map<int,int> mp;
	mp[0] = 0;
	int pref[n+1]={0};
	for(int i=0; i<n; i++){
		pref[i+1] = pref[i] + (a[i]==2? 1: -1);
		mp[pref[i+1]] = i+1;
	}
	int ans = 2*n;
	if(mp.count(dif)){
		ans = n-mp[dif];
	}
	for(int i=n; i<2*n; i++){
		if(a[i]==1)dif--;
		else dif++;
		if(mp.count(dif)){
			ans = min(ans, i-n+1 + n-mp[dif]);
		}
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		cout<<solve()<<endl;
	return 0;
}
