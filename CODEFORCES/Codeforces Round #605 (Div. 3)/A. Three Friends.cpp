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


void solve(){
	int a[3];
	for(int i=0; i<3; i++)
		cin>>a[i];
	sort(&a[0], &a[3]);
	if(a[2]-a[0]>1){
		a[0]++;
		a[2]--;
	}else if(a[2]-a[0]==1){
		a[2]--;
	}
	if(a[1]-a[0]>0){
		a[1]--;
	}else if(a[2]-a[1]>0){
		a[1]++;
	}
	cout<<abs(a[0]-a[1])+abs(a[1]-a[2])+abs(a[2]-a[0])<<endl;
	
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
