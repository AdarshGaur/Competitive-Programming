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


void solve(){
	string s;
	cin>>s;
	int ans =0;
	ans += (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0');
	ans += (s[0]-'0') + (s[1]-'0')*100 + (s[2]-'0')*10;
	ans += (s[0]-'0')*10 + (s[1]-'0') + (s[2]-'0')*100;
	cout<<ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}
