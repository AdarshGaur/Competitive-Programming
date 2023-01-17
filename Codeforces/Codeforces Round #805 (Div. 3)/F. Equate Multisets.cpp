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

int const INF = 1e9 +7;
int const mod = 1e9 +7;


void solve(){
	int n;
	cin >> n;
	
	map<int,int> A;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		A[x]++;
	}
	
	int B[n];
	for(int i=0; i<n; i++){
		cin >> B[i];
	}
	
	string ans = "YES";
	for(int i: B){
		bool used = false;
		while(i>0 and !used){
			int x = i;
			if(x&1){
				// make it max;
				while((x<<1) < INF) x <<= 1;
				while(x > 0 and x >= i){
					if(A.find(x) != A.end() and A[x] > 0){
						A[x]--;
						used = true;
						break;
					}
					x >>= 1;
				}
			}
			i >>= 1;
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
