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
#define sz(x) ((ll)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////////////////////// Main functions start from here ///////////////////////

int n, m;
vvi adj;
vi visited(n+1, 0);

bool dfs(int cur, int par){
    if(visited[cur]==1){
        return false;
    }
    visited[cur]=1;
    // if(adj[cur].size()==1){
    //     if(cur==par){
    //         return false;
    //     }
    //     return true;
    // }
    vpii nodes;
    for(auto i: adj[cur]){
        if(i==par){
            continue;
        }else if(cur==par){
            return false;
        }
        bool res = dfs(i,cur);
        if(!res){
            return false;
        }
    }
    return true;
}


signed main()
{
    fast_cin();
    cin>>n>>m;
    adj.resize(n+1);
    int root=1;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].pb(x);
        root = x;
    }
    //for checking if the given graph is connected or not
    // and if there is any self loops present or not
    bool ans = dfs(root,-1);
    // for(int i=1; i<n+1; i++){
    //     if(visited[i]==0){
    //         ans=false;
    //         break;
    //     }
    // }
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}