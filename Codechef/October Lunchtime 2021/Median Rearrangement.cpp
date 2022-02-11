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
// int const mod = 998244353;
// int const N = 1e5 + 7;


int solve(){
	int n, k;cin>>n>>k;
	vi a(n*n);
	for(auto &i: a)cin>>i;
	sort(a.begin(), a.end());
	int half = (n+2)/2 -1;
	auto preficate = [&](int m){
		unordered_set<int> st;
		int cost=0, j=0;
		for(int i=0; i<n; i++){
			for(int l=0; l<half; l++, j++){
				while(st.count(j))j++;
			}
			if(j > m)m=j;
			cost += a[m];
			st.insert(m++);
		}
		return cost <= k;
	};
	int lo = half, hi=n*half, ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)>>1;
		if(preficate(mid)){
			ans = a[mid];
			lo = mid + 1;
		}else{
			hi = mid-1;
		}
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		cout<<solve()<<endl;
	return 0;
}
