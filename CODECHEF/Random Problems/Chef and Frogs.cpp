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

// bool comp(pii a, pii b){
//     return a.fib.fi;
// }


signed main()
{
    fast_cin();
    int n,k,p;
    cin>>n>>k>>p;
    vpii arr(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr[i].fi=x;
        arr[i].se=i+1;
    }
    sort(all(arr));
    int ans[n+1]={0};
    int cnt =1;
    for(int i=1;i<=n;i++){
        if(i>0 && arr[i-1].fi > arr[i-2].fi +k){
            cnt++;
        }
        ans[arr[i-1].se]=cnt;
    }
    // for(auto i:ans){
    //     cout<<i<<' ';
    // }
    // cout<<endl;
    while(p--){
        int a, b;
        cin>>a>>b;
        if(ans[a]==ans[b]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}