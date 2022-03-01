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


int solve(){
	int n;cin>>n;
	string a, b;
	cin>>a>>b;
	int _11=0, _10=0, _01=0, _00=0;
	for(int i=0; i<n; i++){
		if(a[i]=='1' && b[i]=='1')_11++;
		if(a[i]=='1' && b[i]=='0')_10++;
		if(a[i]=='0' && b[i]=='1')_01++;
		if(a[i]=='0' && b[i]=='0')_00++;
	}
	int ans=INF;
	if(_10==0 && _01==0)ans = 0;
	if(_11==0 and _10==0 and _01>0)ans = -1;
	if(_01 == _10)ans = min(ans, _10+_01);
	if(_11 == _00+1)ans = min(ans, _11+_00);
	if(ans == INF)ans = -1;
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		cout<<solve()<<endl;
	}
	return 0;
}
