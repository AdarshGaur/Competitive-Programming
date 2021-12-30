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
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int a[n];
    for(int i=0; i<n;i++)
		cin>>a[i];
	int ans=1;
	vi left(n,1), right(n, 1);
	for(int i=1; i<n; i++){
		if(a[i] > a[i-1])
			left[i] = left[i-1]+1;
		ans = max(ans, left[i]);
	}
	for(int i=n-1; i>0; i--){
		if(a[i-1] < a[i])
			right[i-1] = right[i]+1;
	}
	for(int i=1; i<n-1; i++){
		if(a[i-1] < a[i+1])
			ans = max(ans, left[i-1]+right[i+1]);
	}
	cout<<ans<<endl;
    return 0;
}
