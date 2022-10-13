/*
* Author : @AdarshGaur
*
* Hashing ( No Random bases )
* 
*
* Time Complexities : O(N)
* Space Complexity - O(N)
* 
*/


#include <bits/stdc++.h>
using namespace std;


int modpow(int a, int b, int mod){
	if(a < 0) a += mod;
	a %= mod;
	int r = 1;
	while(b){
		if(b&1){
			r = (r * 1ll * a)%mod;
		}
		a = (a * 1ll * a)%mod;
		b >>= 1;
	}
	return r;
}

const int mod1 = 1e9 +7, mod2 = 987654319;
const int p1 = 137, p2 = 277;
const int N = 1e5 +7;

pair<int,int> pw[N], ipw[N];

void pre(){
	pw[0] = {1,1};
	ipw[0] = {1, 1};
	
	int ip1 = modpow(p1, mod1-2, mod1);
	int ip2 = modpow(p2, mod2 -2, mod2);
	
	for(int i=1; i<N; i++){
		pw[i].first = (pw[i-1].first * 1ll * p1) %mod1;
		pw[i].second = (pw[i-1].second * 1ll * p2) %mod2;
		
		ipw[i].first = (ipw[i-1].first * 1ll * ip1) %mod1;
		ipw[i].second = (ipw[i-1].second * 1ll * ip2) %mod2;
	}
}

struct Hasher{
	int n;
	string s;
	vector<pair<int,int>> hashes;
	
	Hasher(string _s){
		n = _s.size();
		s = _s;
		hashes.push_back({0,0});
		for(int i=0; i<n; i++){
			pair<int,int> hs;
			hs.first = (hashes[i].first + (s[i]-'a'+1) * 1ll * pw[i].first %mod1 ) %mod1;
			hs.second = (hashes[i].second + (s[i]-'a'+1) * 1ll * pw[i].second %mod2) %mod2;
			hashes.push_back(hs);
		}
	}
	
	pair<int,int> hash(int l, int r){ // always remeber these l, r are 1-indexed
		if(l > r or l < 0 or r > n) return {-1,-1};
		pair<int,int> ans;
		ans.first = (hashes[r].first - hashes[l-1].first + mod1) * 1ll * ipw[l-1].first %mod1;
		ans.second = (hashes[r].second - hashes[l-1].second + mod2) * 1ll * ipw[l-1].second %mod2;
		return ans;
	}
	
	pair<int,int> hash(){
		return hash(1, n);
	}
	
};

signed main()
{
	pre();
	
	int n;
	cin >> n;
	while(n--){
		string text, pattern;
		cin >> text >> pattern;
		
		Hasher H(text), pat(pattern);
		auto hval = pat.hash(); // {1 , n}
		int pos = -1, ps = pattern.size();
		for(size_t i=0; i + ps-1 < text.size(); i++){
			if(H.hash(i+1, i + ps) == hval){
				pos = i;
			}
		}
		
		if(pos == -1){
			cout << "NO MATCH FOUND" << endl;
		}else{
			cout << "MATCH FOUND AT POS : " << pos+1 << endl;
		}
	}
}
