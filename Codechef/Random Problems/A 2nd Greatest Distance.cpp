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



int solve(){

}


signed main()
{
    fast_cin();
                
    int n;cin>>n;
    int x[n], y[n];
    forn(i,0,n){
        cin>>x[i]>>y[i];
    }
    int a=x[0],b=y[0],c=x[0],d=y[0];
    int a2=y[0], b1=x[0], c2=y[0], d1=x[0];
    int ta,tb,tc,td;
    int ta2, tb1, tc2, td1;
    forn(i,0,n){
        a=min(a,x[i]);
        c=max(c,x[i]);
        d=max(d,y[i]);
        b=min(b,y[i]);
    }
    if(abs(a-c)>abs(b-d)){
        int ign1 = a;
        int ign2 = c;
    }else{
        int ign1 = b;
        int ign2 = d;
    }
    forn(i,0,n){

    }
    int f1 = max(abs(a-c),abs(b-d));
    
    return 0;
}