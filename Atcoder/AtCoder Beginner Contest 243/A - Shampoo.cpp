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
	int v , a, b, c;
	cin >> v >> a >> b >> c;
	int s = a+b+c;
	v %= s;
	v -= a;
	if( v < 0){
		cout << "F";
		exit(0);
	}
	v -= b;
	if(v < 0 ){
		cout << "M";
	}else{
		cout << "T";
	}
	return 0;
}
