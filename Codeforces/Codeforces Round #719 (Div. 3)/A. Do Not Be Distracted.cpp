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
	string s;cin>>s;
	vi lett(150,0);
	char last=s[0];
	lett[(int)(s[0])]=1;
	bool ans=true;
	fore(i,1,n){
		if(lett[(int)(s[i])] && last!=s[i]){
			ans=false;
		}
		last = s[i];
		lett[(int)(s[i])]=1;
	}
	if(ans){
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
