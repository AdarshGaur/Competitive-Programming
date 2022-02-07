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


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m, k;cin>>n>>m>>k;
	int a[n], b[n], c[n];
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int fp[n];
	iota(fp, fp+n, 0);
	for(int i=0; i<m; i++){
		int u, v;cin>>u>>v;
		u--, v--;
		fp[v] = max(fp[v], u);
	}
	vector<vi> g(n);
	for(int i=0; i<n; i++){
		g[fp[i]].push_back(i);
	}
	multiset<int> defended;
	for(int i=0; i<n; i++){
		while(k<a[i] and !defended.empty()){
			k++;
			defended.erase(defended.begin());
		}
		if(k<a[i]){
			cout<<-1<<endl;
			exit(0);
		}
		k += b[i];
		for(auto v : g[i]){
			k--;
			defended.insert(c[v]);
		}
	}
	while(k<0){
		defended.erase(defended.begin());
		k++;
	}
	int sum=0;
	for(auto i: defended)sum+=i;
	cout<<sum<<endl;
	return 0;
}
