// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;

void solve(){
	int n;
	cin >> n;
	vi a(n), f(n+1, 0);
	for(int i=0; i<n; i++){
		cin >> a[i];
		f[a[i]] += 1;
	}
	int mex = 0;
	for(int i=0; i<=n; i++){
		if(f[i] == 0){
			mex = i;
			break;
		}
	}
	stack<pii> extras;
	vi ans;
	for(int i=0; i<=mex; i++){
		ans.push_back(f[i]);
		if(f[i] > 1){
			extras.push({i, f[i]-1});
		}
	}
	int hard = 0, last = mex;
	for(int i=mex+1; i<=n; i++){
		if(!extras.size() and last < i){
			ans.push_back(-1);
		}else{
			if(i-1 == last){
				auto [v, x] = extras.top();
				extras.pop();
				hard += i-1 - v;
				if(x-1) extras.push({v,x-1});
			}
			last = (f[i] == 0 ? i: i+1);
			ans.push_back(hard + f[i]);
			if(f[i] > 1) extras.push({i, f[i]-1});
		}
	}
	for(int i : ans){
		cout << i << " ";
	}
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
