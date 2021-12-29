// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;

vector<vi> L;
int ans, n, x;

void dfs(int pos, int res){
	if(pos==n){
		if(res==x)ans++;
	}else{
		for(auto k : L[pos]){
			if(res <= x/k){
				dfs(pos+1, res*k);
			}
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
	cin>>n>>x;
	L = vector<vi>(n);
	for(int i=0; i<n; i++){
		int l;cin>>l;
		for(int j=0; j<l; j++){
			int a;cin>>a;
			L[i].push_back(a);
		}
	}
	dfs(0,1);
	cout<<ans<<endl;
    return 0;
}
