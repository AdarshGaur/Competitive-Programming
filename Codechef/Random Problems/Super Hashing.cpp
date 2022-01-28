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


const int smax = 1380;
int dp[53][53][smax];

signed main()
{
    fast_cin();
    dp[1][1][1]=1;
    dp[1][0][0]=1; //for later values which just need to account for its own char value with just 1 lenght short.
                   // eg. dp[2][2][1] needs dp[2][1][1] and um ..... fuck i can't explain
    for(int i=2; i<53; i++){//char
        dp[i][0][0]=1; // same thing as the last commented statement, for everry i
        for(int j=1; j<=i; j++){//len
            for(int k=1; k<smax; k++){// hash value
                dp[i][j][k] = dp[i-1][j][k];
                if(k-i>=0 && j-1>=0){
                    dp[i][j][k] += dp[i-1][j-1][k-i];
                }
            }
        }
    }
    int it;cin >> it;
    for(int a=1; a<=it; a++){
        cout << "Case " <<a<< ": ";
        int l, s;
        cin>>l>>s;
        if(s>1378 || l>53){
            cout<<0<<endl;
            continue;
        }
        cout<<dp[52][l][s]<<endl;
    }
    return 0;
}