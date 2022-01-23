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

#define INF 2e16
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n;cin>>n;
	vi a, b;
	for(int i=0; i<n; i++){
		int x;cin>>x;
		a.push_back(x);
		if(i==n-1){
			break;
		}
		cin>>x;
		b.push_back(x);
		i++;
	}
	vi costa, costb;
	int totala=0, totalb=0, mna=INF, mnb=INF;
	for(int i=0; i<(int)a.size(); i++){
		if(mna >  a[i]){
			mna = a[i];
		}
		totala += a[i];
		//find the cost of the segments till here
		int cost = totala + mna*(n-i-1);
		costa.push_back(cost);
	}
	for(int i=0; i<(int)b.size(); i++){
		if(mnb >  b[i]){
			mnb = b[i];
		}
		totalb += b[i];
		//find the cost of the segments till here
		int cost = totalb + mnb*(n-i-1);
		costb.push_back(cost);
	}
	for(int i=0; i<3; i++){
		costa.push_back(INF);
		costb.push_back(INF);
	}	
	
	int ans=INF;
	for(int i=0; i<(int)costb.size()-1; i++){
		int temp = min(costa[i]+costb[i], costa[i+1]+costb[i]);
		ans = min(ans , temp);
	}
	cout<<ans<<endl;
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
