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


void solve(){
    int n;cin>>n;
    int res=INF;
    for(int i=1;i*i<n;i++){
        if(n%i==0){
            int x, y;
            x=n/i;
            y=i;
            if((x+y)%2==0){
                res=min(res,(x-y)/2);
            }
        }
    }
    if(res==INF){
        cout<<-1<<endl;
    }else{
        cout<<res*res<<endl;
    }

}

signed main()
{
    fast_cin();
    cout << setprecision(15) << fixed;
    int it;cin >> it;
    while(it--){
    //cout << "Case #" << it+1 << ": ";
    solve();
    }
    
    return 0;
}