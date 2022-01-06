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

set<int> s;
void init(){
	s.insert(1);
	for(int i=2; i<N; i++){
		s.insert(i*i);
		s.insert(i*i*i);
	}
}

void solve(){
	int n;cin>>n;
	int ans=0;
	for( auto ik = s.begin(); ik!=s.end(); ik++){
		if(*ik>n)break;
		ans++;
	}
	cout<< ans <<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

	init();
    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
