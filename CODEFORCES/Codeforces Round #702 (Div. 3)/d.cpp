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

int n;
int a[102], depth[102];

void partition(int start, int end, int d){
	if(start>end)return;
	if(start==end){
		depth[start]=d;
		return;
	}
	int mx=0, ind=0;
	for(int i=start; i<=end; i++){
		if(mx < a[i]){
			mx = a[i];
			ind = i;
		}
	}
	depth[ind]=d;
	partition(start, ind-1, d+1);
	partition(ind+1, end, d+1);
}

void solve(){
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i];
	partition((int)0,n-1,(int)0);
	for(int i=0; i<n; i++){
		cout<<depth[i]<<" ";
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
