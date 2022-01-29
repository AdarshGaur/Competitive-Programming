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

const int N = 1e4 +7;
int cubes[N];

void init(){
	cubes[0]=1;
	for(int i=1; i<N; i++){
		int x = i+1;
		cubes[i] = x*x*x;
	}
}

void solve(){
	int n;
	cin>>n;
	for(int i=0; i<N; i++){
		int x = n-cubes[i];
		if(binary_search(&cubes[0], &cubes[N], x)){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	init();
    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
