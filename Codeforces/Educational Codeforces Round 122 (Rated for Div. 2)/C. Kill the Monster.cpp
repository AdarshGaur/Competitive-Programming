// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)
#define ff first
#define ss second

int const INF = 2e10;
int const INF2 = 2e15;
int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;


string solve(){
	int hc ,dc, hm, dm, k, w, a;
	cin>>hc>>dc>>hm>>dm>>k>>w>>a;
	for(int i=0; i<=k; i++){
		int new_hc = hc + i*a;
		int left_w = w*(k-i);
		int x = (new_hc+dm-1)/dm;
		int y = (hm+dc+left_w-1)/(dc+left_w);
		if(x>=y)return "YES";
	}
	return "NO";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		cout<<solve()<<endl;
	return 0;
}
