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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, m;
	cin>>n>>m;
	vi ans;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int d1 = n-i + m-j;
			int d2 = n-i + j-1;
			int d3 = i-1 + m-j;
			int d4 = i-1 + j-1;
			ans.push_back(max({d1,d2,d3,d4}));
		}
	}
	sort(ans.begin(), ans.end());
	for(int i=0; i<n*m; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
