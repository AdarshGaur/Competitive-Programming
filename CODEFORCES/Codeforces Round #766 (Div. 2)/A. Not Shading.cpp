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
	int n, m, r, c;
	cin>>n>>m>>r>>c;
	r--, c--;
	string s[n];
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	bool black=false;
	int ans=2;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j]=='B'){
				black=true;
				if(i==r and j==c){
					cout<<0<<endl;
					return;
				}else if(i==r || j==c){
					ans=1;
				}
			}
		}
	}
	if(!black){
		ans = -1;
	}
	cout<<ans<<endl;
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
