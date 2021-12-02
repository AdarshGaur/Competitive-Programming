// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second
#define ii (int)

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    int n, m, k;
    cin>>n>>m>>k;
    int i=k, j=k, ans=0;
    if(m>=n){
		m-=n;
		ans++;
	}
	int sum = abs(k-i)+abs(k-j)+1;
    while(sum<=m){
		m-=sum;
		ans++;
		i = max(i-1, ii 1);
		j = min(j+1, n);
		sum = abs(k-i) + abs(k-j) +1;
		if(i==1 and j==n)break;
	}
	if(i==1 and j==n){
		ans += m/n;
	}
	cout<<ans<<endl;
    return 0;
}
