/*
* Author : Adarsh Gaur 
*
* Sparse Table
* Time Complexity 				- O(NlogN) for precomputation
* For Idempotent Functions 		- O(1) for query
* For non-idempotent function 	- O(logN) for query
* Space Complexity				- O(NlogN)
*
*/


#include <bits/stdc++.h>
using namespace std;
#define int int64_t


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

signed main(){

	int n;
	cin>>n;
	vector<int> A(n);
	for(int &i: A)
		cin >> i;

	SparseTable<int> st(A, [](int i, int j){
		return min(i, j);
	});

	int q;cin>>q;
	while(q--){
		int l ,r;
		cin>>l>>r;
		// 0 - based indexing
		cout<<st.get(l,r)<<endl;
	}
	return 0;
}
