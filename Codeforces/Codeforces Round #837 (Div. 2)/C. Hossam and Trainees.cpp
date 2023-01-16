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


const int N = 1e5 +7;

vector<int> primes;
vector<bool> isPrime(N, true);	//isPrime[i] indicates i is prime.

void sieve(){
	// 0, 1 are non-primes
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i <= N; i++){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j = i*i; j <= N; j+=i ){
				isPrime[j] = false;
			}
		}
	}
}


void solve(){
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	bool found = false;
	map<int,bool> mp;
	for(int &v: a){
		for(auto &i : primes){
			if(i*i > v) break;
			if(v % i == 0){
				while(v % i == 0) v /= i;
				if(mp.find(i) != mp.end()){
					found = true;
					break;
				}else{
					mp[i] = true;
				}
			}
		}
		if(v > 1){
			if(mp.count(v)){
				found = true;
			}else{
				mp[v] = true;
			}
		}
		if(found) break;
	}
	cout << (found ? "YES" : "NO") << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	sieve();

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
