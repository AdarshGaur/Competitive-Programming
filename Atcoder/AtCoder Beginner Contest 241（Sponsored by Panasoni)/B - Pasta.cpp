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
	int n, m;cin>>n>>m;
	int a[n], b[m];
	map<int,int> mp;
	for(int i=0; i<n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	string ans="Yes";
	for(int i=0; i<m; i++)cin>>b[i];
	for(int i=0; i<m; i++){
		if(mp.count(b[i])!=0){
			if(mp[b[i]]==0){
				ans="No";
				break;
			}
			mp[b[i]]--;
		}else{
			ans="No";
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
