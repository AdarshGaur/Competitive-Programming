// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int mod = 1e9 +7;
//const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin>>n>>x;
    vector<vi> l(n);
    for(int i=0; i<n; i++){
		int L;cin>>L;
		for(int j=0; j<L; j++){
			int y;cin>>y;
			l[i].push_back(y);
		}
	}
	vi product = l[0];
	for(int i=1; i<n; i++){
		vi temp;
		int cnt=0;
		for(int j=0; j<(int)l[i].size(); j++){
			for(auto k :product){
				if(k <= x/l[i][j]){
					temp.push_back(k*l[i][j]);
					cnt++;
				}
			}
		}
		if(cnt==0){
			cout<<0<<endl;
			return 0;
		}
		product = temp;
	}
	int ans=0;
	for(auto i : product){
		if(i==x)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
