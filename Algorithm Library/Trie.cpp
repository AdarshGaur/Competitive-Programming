// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

struct node{
	int child[26];
	bool isWord = false;
	node(){
		memset(child, -1, sizeof(child));
		isWord = false;
	}
};

struct Trie{
	vector<node> T;
	Trie(){
		T.emplace_back();
	}
	
	void insert(string &s){
		int cur = 0;
		for(auto &c: s){
			int index = c - 'a';
			if(T[cur].child[index] == -1){
				T[cur].child[index] = (int)T.size();
				T.emplace_back();
			}
			cur = T[cur].child[index];
		}
		T[cur].isWord = true;
	}
	
	bool query(string& s){
		int cur = 0;
		for(auto &c : s){
			int index = c - 'a';
			if(T[cur].child[index] == -1) return false;
			cur = T[cur].child[index];
		}
		return T[cur].isWord;
	}
	
	bool startsWith(string& s){
		int cur = 0;
		for(auto& c: s){
			int index = c - 'a';
			if(T[cur].child[index] == -1) return false;
			cur = T[cur].child[index];
		}
		return true;
	}
	
};


signed main()
{
	auto T = Trie();
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		int x;
		cin >> x >> s;
		if(x == 1)
			T.insert(s);
		else if(x == 2)
			cout << (T.query(s) ? "YES" : "NO") << endl;
		else
			cout << (T.startsWith(s) ? "YES" : "NO" ) << endl;
	}
	return 0;
}
