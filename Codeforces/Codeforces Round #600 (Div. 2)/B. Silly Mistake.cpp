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
	int n;cin>>n;
	vi arr(n);
	fore(i,0,n){
		cin>>arr[i];
	}
	vi ans;
	unordered_map<int,int> indx;
	int count=0;
	bool pos=true;
	set<int> s;
	for(auto i: arr){
		count++;
		int j = abs(i);
		if(indx[j]==0){
			if(i>0){
				indx[j]++;
				s.insert(i);
			}else{
				pos=false;
				break;
			}
		}
		else if(indx[j]==1){
			if(i>0){
				pos=false;
				break;
			}else{
				auto it = s.find(-i);
				s.erase(it);
				indx[j]++;
			}
			
			if(sz(s)==0){
				ans.pb(count);
				count=0;
				indx.clear();
			}
		}
		else{
			pos=false;
			break;
		}
	}

	if(count!=0){
		if(sz(s)!=0){
			pos=false;
		}
		ans.pb(count);
	}
	
	if(!pos){
		cout<<-1<<endl;
	}else{
		cout<<sz(ans)<<endl;
		for(auto i:ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}

signed main()
{
    fast_io;
    solve();
    return 0;
}
