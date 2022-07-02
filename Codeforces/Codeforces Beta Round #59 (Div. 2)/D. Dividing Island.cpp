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
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int arr[n];
	for(int &i: arr)
		cin >> i;
	char start = 'a';
	int row = max(b, d), x = d-1, y = a, s = 0, dir = 1;
	if(x%2 == 0){
		y = a+c-1;
		dir = -1;
	}
	vector<vector<char>> mat(row, vector<char>(a+c, '.'));
	for(; x>=0; x--){
		for(int j = 0; j<c; j++){
			if(arr[s] == 0) start++, s++;
			mat[x][y] = start;
			y += dir;
			arr[s]--;
		}
		y -= dir;
		dir *= -1;
	}
	x = 0, y = a-1, dir = -1;
	for(int i=0; i<b; i++){
		for(int j=0; j<a; j++){
			if(arr[s] == 0) s++, start++;
			mat[i][y] = start;
			y += dir;
			arr[s]--;
		}
		y -= dir;
		dir *= -1;
	}
	cout << "YES" << endl;
	for(auto &v: mat){
		for(auto& ch: v)
			cout << ch;
		cout << endl;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
