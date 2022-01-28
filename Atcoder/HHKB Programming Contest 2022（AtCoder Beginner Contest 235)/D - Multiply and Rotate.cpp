// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

// int const INF = 2e18;
int const mod = 1e9 +7;
//int const mod = 998244353;
int const N = 1e5 + 7;


void solve(){
	int a, s;
	cin>>a>>s;
	map<int,int> mp;
	int m=1;
	while(m<=s)m*=10;
	deque<int> q;
	q.push_back(1);
	mp[1]=0;
	while(!q.empty()){
		int n = q.front();
		q.pop_front();
		int cnt = mp[n];
		int x = n*a;
		if(x < m and mp.count(x)==0){
			q.push_back(x);
			mp[x] = cnt+1;
			// aster(x);
		}
		if(n>10 and n%10!=0){
			string k = to_string(n);
			string ss = k[k.size()-1] + k.substr(0,k.size()-1);
			x = stoi(ss);
			if(x <m and mp.count(x)==0){
				q.push_back(x);
				mp[x] = cnt+1;
				// aster(x);
			}
		}
	}
	if(mp.count(s)==0)
		mp[s] = -1;
	cout<<mp[s]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}
