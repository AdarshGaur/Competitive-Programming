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
	int n, k;cin>>n>>k;
	string s;cin>>s;
	int i=1;
	while(i<n){
		int x = 0, y = i;
		bool found = false;
		while(x<i){
			if(s[x] != s[y%n]){
				found = s[x] < s[y%n];
				break;
			}
			x++,y++;
		}
		if(found){
			s = s.substr(0,i);
			break;
		}
		i = max(i+1, y);
	}
	while( ii(s.size()) < k){
		s += s;
	}
	cout << s.substr(0, k) <<endl;
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
