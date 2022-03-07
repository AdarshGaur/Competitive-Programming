// Author : Adarsh Gaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n, k;
	cin>>n>>k;
	vi a(k);
	for(int i=0; i<k; i++)cin>>a[i];
	a.push_back(n);
	sort(a.begin(), a.end());
	int cat=0, mice=a[k-1], cnt=0;
	for(int i=k-1; i>=0; i--){
		mice = a[i];
		if(cat < mice){
			cnt++;
			cat += n - mice;
		}else{
			break;
		}
	}
	cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int times=1;
    cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
