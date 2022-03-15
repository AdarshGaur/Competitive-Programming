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
	string s;
	int n, k;
	cin >> n >> k >> s;
	int l=0, r=0, ans=0, a=0, b=0;
	while(r < (int)s.size()){
		if( s[r] == 'a') a++;
		else b++;
		while( l < r and min(a, b) > k){
			if(s[l] == 'a')a--;
			else b--;
			l++;
		}
		ans = max( ans, r-l+1);
		r++;
	}
	cout << ans << endl;
	return 0;
}
