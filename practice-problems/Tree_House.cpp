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
typedef vector<vector<pii> > vvp;
typedef vector<pii> vpii;
#define forn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s,e) for(int i = s; i >= e; i--)
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

const int mod = 1e9 +7;

vvi adj;
int n;

// bool comp(pii a, pii b){///////// problem
//     return a.first>=b.first;
// }


int dfs(int cur, int par){
    vpii nodes;
    for(auto i: adj[cur]){
        if(i==par){
            continue;
        }
        int val = dfs(i,cur);
        nodes.push_back({val,i});
    }
    if(nodes.empty()){
        return 1;
    }
    sort(nodes.rbegin(), nodes.rend());
    /// sort(nodes.begin(),nodes.end(), greater<int>());
    int j=1, sum=1;
    for(auto i:nodes){
        int temp = i.fi*j;
        sum += temp;
        j++;
    }
    return sum;
}

void solve(){
    int x;
    cin>>n>>x;
    adj.clear();
    adj.resize(n+1);
    forn(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = dfs(1, -1);
    ans = ((ans%mod)*(x%mod))%mod;
    cout<<ans<<endl;
}

signed main()
{
    fast_cin();
    int it;cin >> it;
    while(it--){
    //cout << "Case #" << it+1 << ": ";
    solve();
    }
    return 0;
}

