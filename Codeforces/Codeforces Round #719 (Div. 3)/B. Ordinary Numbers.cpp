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
	cin >>n;
	int ans=0, h=1, count=0;
	while(h<=n){
		h*=10;
		count++;
	}
	if(h!=n){
		h/=10;
		count--;
	}
	ans = 9 * count;
	int t = (int)n/h;
	ans += t;
	string s = to_string(n);
	int a = (int)(s[0]);
	fore(i,1,sz(s)){
		int x = (int)(s[i]);
		if(x<a){
			ans--;
			break;
		}else if(x>a){
			break;
		}
	}
	cout<<ans<<endl;
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
