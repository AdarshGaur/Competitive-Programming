/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<pii> vpii;


#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forn(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e10
#define endl "\n"

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////// Main functions start from here ////////



signed main()
{
    fast_cin();
    int n;cin>>n;
    int h[n+1], width[n+1];
    for(int i=1;i<=n; ++i){
		cin>>width[i]>>h[i];
	}
	
	set<int> s;
	int ans=1;
	s.insert(h[1]);
	
	for(int i=2; i<=n; i++){
		auto itr = s.find(h[i]);
		
		if(h[i]>h[i-1]){
			s.insert(h[i]);
			ans++;
		
		}else if(h[i]<h[i-1]){
			auto it = s.upper_bound(h[i]);
			s.erase(it, s.end());
			if(itr==s.end()){
				ans++;
				s.insert(h[i]);
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
