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
//int const mod = 998244353;
//int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	vi arr;
	int half = (n+1)/2, dec=0, inc=-1, start=(n&1?n:n-1);
	for(int i=start; i>half; i--){
		arr.push_back(i);
		dec++;
	}
	for(int i=1; i<=half; i++){
		if(i==2 and n%2==0){
			arr.push_back(n);
		}
		arr.push_back(i);
		inc++;
	}
	if(inc == dec and dec>0){
		cout<<"YES"<<endl;
		for(auto i:arr)cout<<i<<" ";
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
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
