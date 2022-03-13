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
	int n, x=0;
	cin >> n;
	int a[n], b[n];
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	map<int, int> ma, mb;
	for(int i=0; i<n; i++){
		if(a[i] == b[i]){
			x++;
		}
		ma[a[i]]++;
		mb[b[i]]++;
	}
	int y=0;
	for(auto [u,v]: ma){
		if(mb.count(u)){
			y += v*mb[u];
		}
	}
	cout << x << "\n" << y-x << endl;
	return 0;
}
