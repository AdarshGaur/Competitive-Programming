// Author : Adarsh Gaur 

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
int const N = 1e6 + 7;

void solve(){
	int x; cin >> x;
	string s, cut;
	cin >> s;
	s = '#' + s;
	int l = 0, c = 0;
	while( l <= x){
		l++;
		cut = s.substr(l+1);
		for(auto i='1'; i<s[l]; i++){
			s += cut;
		}
		if((int)s.size() > x) break;
	}
	if(l == x ){
		cout << s.size()-1 << endl;
	}else{
		c = s.size() - l -1;
		for(int i=l; i<x;){
			i++;
			c--;
			c = (s[i]-'0')*c;
			c %= mod;
		}
		c += x;
		c %= mod;
		cout << c << endl;
	}
			
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
