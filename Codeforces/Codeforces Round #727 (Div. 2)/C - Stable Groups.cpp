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
	int n, k,x;
	cin>>n>>k>>x;
	vi a(n);
	fore(i,0,n){
		cin>>a[i];
	}
	sort(all(a));
	int ans=1;
	vi blocks;
	fore(i,1,n){
		if(a[i]-a[i-1]>x){
			ans++;
			blocks.pb(a[i]-a[i-1]);
		}
	}
	sort(all(blocks));
	for(auto i:blocks){
		int segments = i/x;
		segments--;
		if(i%x){
			segments++;
		}
		if(segments<=k){
			k-=segments;
			ans--;
		}else{
			break;
		}
	}
	cout<<ans<<endl;
} 

signed main()
{
    fast_io;
	cout.precision(20);
    //int times;cin >> times;
    //for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
    solve();
    //}
    return 0;
}
