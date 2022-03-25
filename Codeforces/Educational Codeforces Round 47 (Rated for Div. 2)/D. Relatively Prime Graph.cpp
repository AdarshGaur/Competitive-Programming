// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, m;
	cin >> n >> m;
	if(m < n-1 or m > (n*(n-1))/2 ){
		cout << "Impossible\n";
		return 0;
	}
	vector<pii> edges;
	for(int i=2; i<=n; i++){
		edges.push_back({1, i});
	}
	m -= (n-1);
	int i = 2, j = 3;
	while(m > 0){
		if(j > n){
			i++;
			j = i+1;
		}
		if(j>n)break;
		if(__gcd(i, j) == 1){
			edges.push_back({i, j});
			m--;
		}
		j++;
	}
	if(m){
		cout << "Impossible\n";
	}else{
		cout << "Possible" << endl;
		for(auto [u, v]: edges){
			cout << u << " " << v << endl;
		}
	}
	return 0;
}
