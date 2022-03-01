// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	vi a(n);
	for(auto &i:a)cin>>i;
	if(a[n-1]<a[n-2]){
		cout<<-1<<endl;
		return;
	}
	map<int, pii> mp;
	int mx=-INF, ind=-1, mn, mnind;
	for(int i=n-1; i>0; i--){
		if(mx < a[i]){
			mx = a[i];
			ind = i;
		}
		mp[i-1] = {mx, ind};
	}
	mnind = n-2;
	mn = a[mnind];
	vi b = a;
	vector<tuple<int,int,int>> ans;
	for(int i=n-3; i>=0; i--){
		if(b[i+1] < mn){
			mn = a[i+1];
			mnind = i+1;
		}
		mx = mp[mnind].ff;
		ind = mp[mnind].ss;
		if( mn - mx <= a[i+1]){
			while(i>=0){
				a[i] = mn - mx;
				ans.push_back({i+1, mnind+1, ind+1});
				i--;
			}
			break;
		}
	}
	for(int i=1; i<n; i++){
		if(a[i] < a[i-1]){
			cout<<-1<<endl;
			return;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(auto [u,v,w]:ans){
		cout<<u<<" "<<v<<" "<<w<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		//cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
