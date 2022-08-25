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

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

bool isVowel(char c){
	for(int i=0; i<5; i++)
		if(c == vowels[i])
			return true;
	return false;
}

int change(char a, char b){
	if(a == b) return 0;
	if(( isVowel(a) and isVowel(b)) or (!isVowel(a) and !isVowel(b)) ) return 2;
	return 1;
}


void solve(){
	string s;
	cin >> s;
	
	int ans = INF;
	for(char c = 'A'; c <= 'Z'; c++){
		int moves = 0;
		for(char& i : s){
			moves += change(c, i);
		}
		ans = min(moves, ans);
	}
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
