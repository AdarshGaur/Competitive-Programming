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
//const int mod = 1e9 +7;
const int mod = 998244353;



void solve(){
	int n;cin>>n;
	int a = -(n-1);
	int b = n;
	cout<<a<<" "<<b<<endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	int times=1;
	cin >> times;
	for(int i=1;i<=times; ++i){
		//cout<<"Case #"<< i << ": ";
		solve();
	}
	return 0;
}
