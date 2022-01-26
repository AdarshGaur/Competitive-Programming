// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
	int n, m, k;
	cin>>n>>m>>k;
	auto check = [&](int ans){
		int cnt=0;
		for(int i=1; i<=n; i++){
			cnt += min(m, (ans-1)/i);
		}
		if(cnt < k)return true;
		return false;
	};
	int l = 1, r = n*m;
	while(l<=r){
		int m = l + (r-l)/2;
		if(check(m)){
			l = m+1;
		}else{
			r = m-1;
		}
	}
	cout<<l-1<<endl;
    return 0;
}

