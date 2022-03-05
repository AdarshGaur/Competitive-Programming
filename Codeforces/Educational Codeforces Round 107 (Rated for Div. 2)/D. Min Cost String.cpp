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
	int n, k;
	cin >> n >> k;
	int f[k];
	for(int i=0; i<k; i++){
		f[i] = i;
	}
	string s(1, 'a');
	int i = 0;
	while((int)s.size() < n){
		s += 'a' + f[i];
		int next = f[i];
		f[i] = (f[i]+1)%k;
		i = next;
	}
	cout << s << endl;
	return 0;
}
