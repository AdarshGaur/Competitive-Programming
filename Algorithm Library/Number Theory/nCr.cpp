// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
int const INF = 2e18;
int const mod = 1e9 +7;
int const MAXN = 1e5 +7;

// Precompute fatorials and inverse factorials
int fact[MAXN], invf[MAXN];

void factorials(){
	fact[0] = invf[0] = invf[1] = 1;
	for(int i = 1; i < MAXN; i++){
		fact[i] = (fact[i-1] * i) % mod;
	}
	for(int i = 2; i < MAXN; i++){
		invf[i] = (mod - mod/i) * invf[mod % i] % mod;
	}
	for(int i = 1; i < MAXN; i++){
		invf[i] = (invf[i] * invf[i-1]) % mod;
	}
}

// Find the nCr using fermat little theroem in O(1)
int nCr(int n, int r){
	if( r == 0) return 1;
	if( n < r ) return 0;
	int ans = (fact[n] * invf[n-r]) % mod;
	return (ans * invf[r]) % mod;
}

signed main(){
	factorials();
	int n, r;
	cin >> n >> r;
	cout << nCr(n , r) << endl;
	return 0;
}
