/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vpii;


#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; i++)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define pb push_back
#define ff first
#define ss second


/////// Main functions start from here ////////

#define INF 2e18
const int mod = 1e9 +7;
int n, p, cnt;
vi visited;
vvi adj;

void init(){
    adj.resize(n+1);
    visited.resize(n, false);
}

void dfs(int cur, int par){
    visited[cur]=true;
    cnt++;
    for(auto i:adj[cur]){
        if(!visited[i]){
            dfs(i, cur);
        }
    }
}

signed main()
{
    fast_io;
    cin>>n>>p;
    init();
    fore(i,0,p){
        int x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi ans;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            cnt=0;
            dfs(i,-1);
            ans.pb(cnt);
        }
    }
    int res=0, sum=0;
    for(int i=0; i<sz(ans)-1; i++){
        res += sum*i;
        sum += i;
    }
    cout<<res;
    return 0;
}
