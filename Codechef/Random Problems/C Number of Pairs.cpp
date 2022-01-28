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
#define INF 1e10
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define abs(x) ((x < 0)?-(x):(x))




/////////////////////// Main functions start from here ///////////////////////





void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int a=0;
    for(int i=0; i<n; i++){
        a += upper_bound(arr, arr+n, r-arr[i])-arr;
        a -= lower_bound(arr, arr+n, l-arr[i])-arr;
        if(2*arr[i]>=(l) && 2*arr[i]<=(r)){
            a--;
        }
    }
    cout<<a/2<<endl;
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