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
	string s;cin>>s;
	string ans="YES";
	int a=0, b=0;
	for(int i=0; i<n; i++){
		a += (s[i]=='0');
		b += (s[i]=='1');
	}
	if(a>1 or b>1){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
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
