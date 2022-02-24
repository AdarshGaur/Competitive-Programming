// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

void solve(){
	int n;cin>>n;
	int a[n];
	for(int& i:a)cin>>i;
	int ans=2;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int d = a[j]-a[i], jump = j-i;
			int g = __gcd(jump, abs(d));
			d /= g, jump /= g;
			int cnt=1, x=0;
			for(int k=i+jump; k<n; k+=jump){
				x += d;
				if(a[i]+x == a[k])cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	ans = min(ans, n);
	cout<<n-ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
