/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); it++)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define pb push_back
#define ff first
#define ss second

#ifndef ONLINE_JUDGE
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#else
#define aster(x)
#endif

/////// Main Logical code starts from here ////////

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

void solve(){
	char c;
	int n, cnt=0;
	cin>>n>>c;
	string s;cin>>s;
	for(int i=0; i<n; i++){
		cnt += (s[i]!=c);
	}
	if(cnt==0){
		cout<<0<<endl;
	}else if(cnt==1){
		cout<<1<<endl;
		for(int i=n-1; i>=0; i--){
			if(s[i] == c){
				cout<<i+1<<endl;
				break;
			}
		}
	}else{
		int ind=-1;
		for(int i=n-1; i>=0; i--){
			if(s[i]==c){
				ind =i+1;
				break;
			}
		}
		if(ind*2 > n){
			cout<<1<<"\n"<<ind<<endl;
		}else{
			cout<<2<<endl;
			cout<<n-1<<" "<<n<<endl;
		}
	}
}

int32_t main()
{
    fast_io;
    cout.precision(20);
    int times=1;
    cin >> times;
    for(int i=1;i<=times; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
