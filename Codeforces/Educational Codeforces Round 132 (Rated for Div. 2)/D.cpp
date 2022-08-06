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

template<class T, class F = function<T(const T &, const T &)>>
struct SparseTable{
	vector<vector<T>> t;
	F func;

	SparseTable(const vector<T> &a, F f) : t(32 - __builtin_clz(a.size())), func(move(f)) {
		t[0] = a;
		for(size_t i = 1; i < t.size(); i++){
			t[i].resize(a.size() - (1<<i) +1);
			for(size_t j = 0; j < t[i].size(); j++){
				int shift = 1;
				shift <<= i-1;
				t[i][j] = func(t[i-1][j], t[i-1][j + shift]);
			}
		}
	}

	T get(int from, int to){
		if(to < from)
			swap(from, to);
		assert(0 <= from and to <= (int)t[0].size()-1);
		int k = 31 - __builtin_clz(to - from +1);
		return func(t[k][from], t[k][to - (1 << k) +1]);
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(int &i : a)
		cin >> i;
	
	SparseTable<int> st(a, [](int i, int j){
		return max(i, j);
	});
	
	int q;
	cin >> q;
	while(q--){
		int xs, ys, xf, yf, k;
		cin >> xs >> ys >> xf >> yf >> k;
		if(abs(yf - ys) %k != 0 or abs(xs - xf)%k != 0){
			cout << "NO" << endl;
			continue;
		}
		int inc1 = (n - xs)/k, inc2 = (n-xf)/k;
		xs += k*inc1, xf += k*inc2;
		
		if(st.get(ys-1, yf-1) >= min(xs, xf)){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
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
