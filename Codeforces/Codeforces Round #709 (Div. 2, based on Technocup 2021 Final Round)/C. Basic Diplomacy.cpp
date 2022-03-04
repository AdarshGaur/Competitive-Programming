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
// int const N = 2e5 + 7;


void solve(){
	int n, m;cin>>n>>m;
	vector<vi> days(m);
	pii arr[m];
	for(int i=0; i<m; i++){
		int k; cin>>k;
		days[i] = vi(k);
		arr[i] = {k, i};
		for(auto &j: days[i]){
			cin>>j;
		}
	}
	sort(arr, arr+m);
	int mx = (m+1)/2;
	vi res(m);
	map<int, int> chosen;
	for(int i=0; i<m; i++){
		int j = arr[i].second;
		int mn = INF, ind = -1;
		for(auto f: days[j]){
			if(mn > chosen[f]){
				mn = chosen[f];
				ind = f;
			}
		}
		if(mn >= mx){
			cout<<"NO"<<endl;
			return;
		}
		res[j] = ind;
		chosen[ind]++;
	}
	cout<<"YES"<<endl;
	for(auto i:res){
		cout << i << " " ;
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
