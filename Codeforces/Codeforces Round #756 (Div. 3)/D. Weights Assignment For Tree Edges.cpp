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


void solve(){
	int n;cin>>n;
	vi b(n),p(n), w(n,-1), d(n,0);
	int pos=1, mxdis=0;
	for(int i=0; i<n; i++)cin>>b[i];
	for(int i=0; i<n; i++)cin>>p[i];
	for(int i=0; i<n; i++){
		int node = p[i]; // use node-1 (for indexing dumbass)
		int par = b[node-1]-1;
		if(i==0){
			if(par+1 != node){
				pos=-1;
				break;
			}
			w[node-1] = mxdis;
			d[node-1] = mxdis;
			continue;
		}
		if( w[par] == -1){
			pos=-1;
			break;
		}
		int dif = mxdis - d[par];
		w[node-1] = dif +1;
		d[node-1] = d[par] + w[node-1];
		mxdis = d[node-1];
	}
	if(pos==-1){
		cout<<-1<<endl;
		return;
	}
	for(auto i: w){
		cout<<i<<" ";
	}
	cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}

