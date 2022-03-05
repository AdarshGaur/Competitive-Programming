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
	int n,q;
	cin >> n >> q;
	vi s(n);
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
    for(int i = 0; i < q; ++i){
		int t, indx = -1;
		cin >> t;
		for(int j=0; j < n; j++){
			if(s[j]==t){
				indx=j;
				break;
			}
		}
		cout << indx +1 << " ";
		for(int j=indx; j>0; j--){
			s[j] = s[j-1];
		}
		s[0]=t;
	}
	return 0;
}
