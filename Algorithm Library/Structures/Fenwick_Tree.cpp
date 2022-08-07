/*
* Author : @AdarshGaur
*
* Fenwick Tree ( also known as Binary Indexed Tree )
* 
* Time Complexities :
* 	Initialize : O(NlogN)
* 	Point Update : O(logN)
* 	Query : O(logN)
* 
* Space Complexity - O(N)
* 
*/


#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template<class T>
struct FenwickTree{
	vector<T> bit;
	
	FenwickTree(vector<T>& a) : bit(a.size()) {
		for(size_t i=0; i<a.size(); i++){
			add(i, a[i]);
		}
	}
	
	void add(int index, T val){
		for(size_t i = index; i < bit.size(); i |= i+1)
			bit[i] += val;
	}
	
	T sum(int r){
		T res{};
		for(; r >= 0; r = (r&(r+1)) -1)
			res += bit[r];
		return res;
	}
	
	T sum(int l, int r){
		return sum(r) - sum(l-1);
	}
};

signed main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i: a)
		cin >> i;
	
	
	FenwickTree<int> FT(a);
	
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r;
			cin >> l >> r;
			cout << FT.sum(l, r) << endl;
		}else{
			int i, x;
			cin >> i >> x;
			int change = x - a[i];
			a[i] = x;
			FT.add(i, change);
		}
	}
	return 0;
}
