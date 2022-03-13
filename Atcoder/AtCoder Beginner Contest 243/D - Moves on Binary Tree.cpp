// Author : Adarsh Gaur 

// #define NDEBUG
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


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	string s, t="";
	int n, x;
	cin >> n >> x >> s;
	deque<char> dq;
	for(auto i: s){
		if( i == 'U' and !dq.empty() and
		(dq.back() == 'L' or dq.back() == 'R')){
			dq.pop_back();
		}else{
			dq.push_back(i);
		}
	}
	for(auto k: dq){
		if(k == 'L'){
			x = 2*x;
		}else if(k == 'R'){
			x = 2*x +1;
		}else{
			x >>= 1;
		}
	}
	cout << x << endl;
	return 0;
}
