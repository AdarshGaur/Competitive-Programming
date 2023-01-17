// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#ifdef cicada
#include "debug.h"
#else
#define debug(...) "Yume o akiramete shinde kure."
#endif

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;

int const INF = 2e18;
int const mod = 1e9 +7;


void solve(){
	int n;
	cin >> n;
	
	map<int,int> A;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		while(x %2 == 0){
			x >>= 1;
		}
		A[x]++;
	}
	
	int B[n];
	for(int i=0; i<n; i++){
		cin >> B[i];
		while(B[i] % 2 == 0){
			B[i] >>= 1;
		}
	}
	
	string ans = "YES";
	for(int i=0; i<n; i++){
		bool used = false;
		while(B[i] > 0){
			if(A.find(B[i]) != A.end() and A[B[i]] > 0){
				A[B[i]]--;
				used = true;
				break;
			}
			B[i] >>= 1;
		}
		if(!used){
			ans = "NO";
			break;
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
