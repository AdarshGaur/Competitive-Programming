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
	}else if(a[n-2]-a[n-1] <= a[n-2]){
		cout<<n-2<<endl;
		for(int i=1; i<n-1; i++){
			cout<<i<<" "<<n-1<<" "<<n<<endl;
		}
	}else{
		vi b = a;
		sort(b.begin(), b.end());
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]){
				cout<<-1<<endl;
				return;
			}
		}
		cout<<0<<endl;
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
