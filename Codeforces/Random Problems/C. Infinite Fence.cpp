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

string solve(){
	int r, b, k;cin>>r>>b>>k;
	if(r==b)return "OBEY";
	if(r>b)swap(r,b);
	int g = __gcd(r,b);
	r/= g, b/=g;
	int x = (b-1)/r;
	if(x >= k)return "REBEL";
	int dif = b+1 + r*(k-1);
	if( dif < 2*b)return "REBEL";
	return "OBEY";
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
