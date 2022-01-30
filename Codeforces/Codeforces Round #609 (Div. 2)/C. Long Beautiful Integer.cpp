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
//int const mod = 998244353;
//int const N = 1e5 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, k;cin>>n>>k;
	string a;cin>>a;
	int carry=0;
	for(int i=n-1; i>=0; i--){
		if(carry){
			int x = a[i]-'0';
			x++;
			carry = x/10;
			x%=10;
			a[i] = to_string(x)[0];
		}
		if(i-k>=0 and a[i-k] != a[i]){
			if(a[i-k] < a[i]){
				carry=1;
			}
			a[i] = a[i-k];
		}
	}
	string ans;
	if(carry){
		ans += '1';
	}
	for(int i=0; i<n; i++){
		ans += a[i];
	}
	for(int i=k; i < ii(ans.size()); i++){
		ans[i] = ans[i-k];
	}
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	return 0;
}
