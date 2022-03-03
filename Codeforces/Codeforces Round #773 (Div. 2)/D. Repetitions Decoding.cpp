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
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	vector<pii> op;
	vi tandems;
	int len=0;
	while(!a.empty()){
		n = a.size();
		int i = 0, j = 1;
		while( j<n and a[j]!=a[i]){
			j++;
		}
		if(j==n){
			cout<<-1<<endl;
			return;
		}
		for(int k = i+1; k<j; k++){
			op.push_back({len+j+k, a[k]});
		}
		tandems.push_back(2*j);
		a.erase(a.begin()+j);
		a.erase(a.begin()+i);
		reverse(a.begin(), a.begin()+j-1);
		len += 2*j;
	}
	cout<<op.size()<<endl;
	for(auto [u,v]:op){
		cout<<u<<" "<<v<<endl;
	}
	cout<<tandems.size()<<endl;
	for(auto i: tandems){
		cout<<i<<" ";
	}
	cout<<endl;
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
