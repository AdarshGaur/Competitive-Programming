// Author : Adarsh Gaur 

// Problem Name : Valleys and Hills
// Problem url : https://www.codechef.com/DEC21B/problems/VANDH

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
	int n, m;
	cin>>n>>m;
	int l1=n, l2=m;
	if(l1<l2){
		swap(l1,l2);
	}
	string base="", ans="";
	for(int i=0; i<l1; i++){
		base += "01";
	}
	base += "0";
	if(l1==l2){
		ans = base + "1";
	}else{
		int x = l1 - l2-1;
		ans += base.substr(0,2);
		for(int i=2; i<(int)base.size(); i++){
			ans += base[i];
			if(x>0 and base[i]=='0'){
				ans+="0";
				x--;
			}
		}
	}
	if(l1==m){
		for(int i=0; i<(int)ans.size(); i++){
			if(ans[i]=='1'){
				ans[i]='0';
			}else{
				ans[i]='1';
			}
		}
	}
	cout<<(int)ans.size()<<endl;
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
