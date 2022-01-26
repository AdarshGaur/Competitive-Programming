// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cout<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;


void solve(){
    int n;cin>>n;
    pii a[n];
    for(int i=0; i<n; i++)
        cin>>a[i].ss>>a[i].ff;
    auto check = [&](int mid){ //the predicate function
        int invite =0;
        for(int i=0; i<n; i++){
            if(a[i].ss >= mid-1-invite and a[i].ff >= invite)
                invite++;
        }
        return invite >= mid;
    };
    int lo=0, hi=n;
    while(lo <= hi){
        int m = lo + (hi-lo)/2;
        if(check(m)){
            lo = m +1;
        }else{
            hi = m-1;
        }
    }
    cout<<lo-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

