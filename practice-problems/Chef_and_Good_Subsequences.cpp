////////////////////////// Author : Adarsh Gaur ////////////////////////////

#include <bits/stdc++.h>
//#include <array>
//#include <cassert>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpi;
typedef vector<pii> vpii;
#define forn(i,s,e) for(int i = s; i < e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////////////////////// Main functions start from here ///////////////////////


int const mod = 1e9 +7;

signed main()
{
    fast_cin();
    int n,k;
    cin>>n>>k;
    vi arr;
    int freq[8001]={0};
    for(int i=0; i<n; i++){
        int x;cin>>x;
        freq[x]++;
        if(freq[x]==1){
            arr.pb(x);
        }
    }
    k = min(k, (int)1020);
    vvi dp(sz(arr)+1, vector<int>(k+1, 0));
    for(int i=0;i<=sz(arr);i++){
        dp[i][0]=1;
    }
    for(int i=1; i<=sz(arr); i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j]%mod + (freq[arr[i-1]]*dp[i-1][j-1])%mod;
            dp[i][j]%=mod;
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        ans += dp[sz(arr)][i];
        ans%=mod; 
    }
    cout<<ans<<endl;
    return 0;
}