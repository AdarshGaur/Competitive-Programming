// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;cin>>n;
	pii a[n];
	for(int i=0; i<n; i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a, a+n);
	int last = a[0].second;
	int ans=0;
	for(int i=1; i<n; i++){
		if(a[i].second < last){
			ans++;
		}else{
			last = a[i].second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
