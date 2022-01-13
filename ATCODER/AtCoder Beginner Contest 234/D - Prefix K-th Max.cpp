// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;

/* 
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero).
    order_of_key()  - Number of items in a set that are strictly smaller than our item.
*/

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, k;cin>>n>>k;
	int p[n];
	for(int i=0; i<n; i++)
		cin>>p[i];
	o_set s;
	for(int i=0; i<k-1; i++){
		s.insert(p[i]);
	}
	for(int i=k-1; i<n; i++){
		s.insert(p[i]);
		cout<< *(s.find_by_order(i-k+1)) <<endl;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
