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


void solve(){
	string s;
	cin >> s;
	
	int k; cin >> k;
	vector<vector<int>> g(26);
	for(int i=0; i<k; i++){
		string edge;
		cin >> edge;
		int a = edge[0] - 'A', b = edge[1] - 'A';
		g[a].push_back(b);
	}
	
	auto change = [&](char A, char B){
		if(A == B) return (int)0;
		int a = A - 'A', b = B - 'A';
		int cnt = 0;
		
		queue<int> q;
		q.push(a);
		vector<bool> vis(26, false);
		vis[a] = true;
		while(!q.empty()){
			int x = q.size();
			cnt++;
			for(int i=0; i<x; i++){
				auto u = q.front();
				q.pop();
				for(auto v: g[u]){
					if(v == b) return cnt;
					if(!vis[v]){
						q.push(v);
						vis[v] = true;
					}
				}
			}
		}
		return INF;
	};
	
	int ans = INF;
	for(char c = 'A'; c <= 'Z'; c++){
		int moves = 0;
		for(char i: s){
			int x = change(i, c);
			if(x == INF){
				moves = x;
				break;
			}
			moves += x;
		}
		ans = min(ans, moves);
	}
	
	ans = (ans == INF ? -1 : ans);
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
