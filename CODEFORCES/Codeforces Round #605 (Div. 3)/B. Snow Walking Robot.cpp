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
	string s;cin>>s;
	int l=0, r=0, d=0, u=0;
	for(auto i:s){
		if(i=='L')l++;
		else if(i=='R')r++;
		else if(i=='U')u++;
		else if(i=='D')d++;
	}
	int mn1 = min(l, r);
	int mn2 = min(d, u);
	if(mn1==0){
		mn2 = min(mn2, (int)1);
	}
	if(mn2==0){
		mn1 = min(mn1, (int)1);
	}
	string ans="";
	for(int i=0; i<mn1; i++){
		ans += "R";
	}
	for(int i=0; i<mn2; i++){
		ans += "D";
	}
	for(int i=0; i<mn1; i++){
		ans += "L";
	}
	for(int i=0; i<mn2; i++){
		ans += "U";
	}
	int n = (int)ans.size();
	cout<<n<<endl<<ans<<endl;
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
