// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

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

int solve(){
	string s, p;
	cin >> s >> p;
	int j=0, ans =0;
	for(int i=0; i<(int)s.size(); i++){
		while(j<(int)p.size() and p[j] != s[i]){
			j++;
			ans++;
		}
		if(j==(int)p.size())return -1;
		j++;
	}
	while(j<(int)p.size()){
		j++, ans++;
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		int x = solve();
		cout<<"Case #"<<t<<": " << (x == -1 ? "IMPOSSIBLE" : to_string(x)) << endl;
	}
	return 0;
}
