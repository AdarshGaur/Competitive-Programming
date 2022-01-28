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


signed main()
{
    fast_io;
    int n, k;
    cin>>n>>k;
    vi c(n);
    fore(i,0,n){
		cin>>c[i];
	}
	multiset<int> s;
	int colors = 0, ans=0;
	fore(i,0,k){
		auto it = s.find(c[i]);
		if(it==s.end()){
			ans++;
		}
		s.insert(c[i]);
	}
	colors = ans;
	fore(i,k,n){
		auto it = s.find(c[i-k]);
		s.erase(it);
		it = s.find(c[i-k]);
		if(it==s.end()){
			colors--;
		}
		
		it = s.find(c[i]);
		if(it==s.end()){
			colors++;
		}
		s.insert(c[i]);
		ans = max(ans, colors);
	}
	cout<<ans<<endl;
    return 0;
}
