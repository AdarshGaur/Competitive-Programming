/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;


#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define pb push_back
#define ff first
#define ss second


/////// Main functions start from here ////////

#define INF 2e18
const int mod = 1e9 +7;


void solve(){
	int n;
	cin>>n;
	vi a(n), b(n);
	fore(i,0,n){
		cin>>a[i];
	}
	fore(i,0,n){
		cin>>b[i];
		b[i] -= a[i];
	}
	b.pb(0);
	int ans=0, last=0;
	fore(i,0,n+1){
		if(b[i]<0){
			ans=3;
			break;
		}
		if(b[i]!=last){
			ans++;
			last=b[i];
		}
	}
	if(ans<=2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}

signed main()
{
    fast_io;

    int times;cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
