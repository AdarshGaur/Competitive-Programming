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


string solve(){
	int n;cin>>n;
	vi a(4);
	for(int& i:a)cin>>i;
	for(int msk=0; msk<16; msk++){
		auto b = a;
		bool pos=true;
		for(int i=0; i<4; i++){
			if(msk & (1ll<<i)){
				b[i]--,b[(i+3)%4]--;
			}
		}
		if( *max_element(b.begin(), b.end()) > n-2 or *min_element(b.begin(), b.end())<0){
			pos=false;
		}
		if(pos)return "YES";
	}
	return "NO";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		cout<<solve()<<endl;
	}
	return 0;
}
