// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;
	cin >> n;
	pii ab[n];
	for(int i=0; i<n; i++){
		cin >> ab[i].ss >> ab[i].ff;
	}
	sort(ab, ab+n);
	int i=0, j = n-1, cost=0, buy=0;
	while(i<=j){
		if( buy >= ab[i].ff){
			buy += ab[i].ss;
			cost += ab[i].ss;
			i++;
		}else{
			int dif = ab[i].ff - buy;
			if(dif > ab[j].ss){
				buy += ab[j].ss;
				cost += 2*ab[j].ss;
				j--;
			}else{
				buy += dif;
				ab[j].ss -= dif;
				cost += dif*2;
			}
		}
	}
	cout << cost << endl;
	return 0;
}
