// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second


void solve(){
	string p, h;cin>>p>>h;
	sort(p.begin(), p.end());
	int n = h.size(), np = p.size();
	for(auto i=0; i+np<=n; i++){
		string k = h.substr(i, np);
		sort(k.begin(), k.end());
		if(p == k){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	return ;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
