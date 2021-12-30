// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	string s;cin>>s;
	int u = count(s.begin(), s.end(), 'U');
	int r = count(s.begin(), s.end(), 'R');
	int d = count(s.begin(), s.end(), 'D');
	int l = count(s.begin(), s.end(), 'L');
	int mn1 = min(u, d), mn2= min(r, l);
	if(mn1==0)mn2=min(mn2, (int)1);
	if(mn2==0)mn1=min(mn1, (int)1);
	string ans;
	ans += string(mn1, 'U');
	ans += string(mn2, 'R');
	ans += string(mn1, 'D');
	ans += string(mn2, 'L');
	cout<<ans.size()<<endl<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
