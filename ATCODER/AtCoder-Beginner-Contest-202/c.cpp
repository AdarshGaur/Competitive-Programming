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
    cout.precision(20);
    ////////////////////////
    int n;cin>>n;
    int a[n], b[n], c[n];
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0; i<n; i++)cin>>c[i];
    int freq[N]={0};
    for(int i=0; i<n; i++){
		freq[c[i]]++;
	}
	int f[N]={0};
	for(int i=0; i<n; i++){
		f[b[i]] += freq[i+1];
	}
	int ans=0;
	for(auto i: a){
		ans += f[i];
	}
	cout<<ans<<endl;
    return 0;
}
