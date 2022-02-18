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


void solve(){
	int n;cin>>n;
	int a[n];
	for(auto &i:a)cin>>i;
	for(int i=0; i<n; i++){
		int j=i+1, mn = a[i], ind=-1;
		while(j<n){
			if(a[j]<mn){
				mn = a[j];
				ind = j;
			}
			j++;
		}
		if(ind == -1)continue;
		j = ind;
		while(j>i){
			swap(a[j], a[j-1]);
			j--;
		}
		i = ind-1;
	}
	for(auto j:a){
		cout<<j<<" ";
	}
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}
