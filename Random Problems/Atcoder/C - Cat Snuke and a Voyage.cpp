// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

const int N = 2e5 +7;
int p1[N], p2[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		if(x==1){
			p1[y]=1;
		}else if(y==1){
			p1[x]=1;
		}
		if(x==n){
			p2[y]=1;
		}else if(y==n){
			p2[x]=1;
		}
	}
	string ans = "IMPOSSIBLE";
	for(int i=1; i<=n; i++){
		if(p1[i]&p2[i]){
			ans = "POSSIBLE";
		}
	}
	cout<<ans<<endl;
    return 0;
}
