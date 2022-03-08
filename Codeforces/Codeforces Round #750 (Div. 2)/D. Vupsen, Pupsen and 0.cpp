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
	int n;
	cin >> n;
	int a[n];
	for(int &i:a){
		cin >> i;
	}
	int b[n];
	int start = 0;
	if(n&1){
		if(a[0] == -a[1]){
			int neg=0, pos=0;
			for(int i=0; i<3; i++){
				if(a[i] < 0)neg += a[i];
				else pos += a[i];
			}
			for(int i=0; i<3; i++){
				if(a[i] < 0 ) b[i] = pos;
				else b[i] = -neg;
			}
		}else{
			b[2] = a[0] + a[1];
			b[0] = -a[2];
			b[1] = -a[2];
		}
		start = 3;
	}
	for(int i=start; i<n; i+=2){
		b[i] = a[i+1];
		b[i+1] = -a[i];
	}
	for(int i:b){
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
