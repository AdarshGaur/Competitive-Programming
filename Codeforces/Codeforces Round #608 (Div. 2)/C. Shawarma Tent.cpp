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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n;cin>>n;
	int xs, ys;cin>>xs>>ys;
	int a=0, b=0, c=0, d=0;
	int px=xs, py=ys;
	for(int i=0; i<n; i++){
		int x, y;cin>>x>>y;
		// coord[i].ff = x, coord[i].ss=y;
		if(x < xs)a++;
		if(y > ys)b++;
		if(x > xs)c++;
		if(y < ys)d++;
	}
	int ans = max({a,b,c,d});
	cout<<ans<<endl;
	if(a == ans){
		px--;
	}else if(b==ans){
		py++;
	}else if(c==ans){
		px++;
	}else if(d==ans){
		py--;
	}
	cout<<px<<" "<<py<<endl;
	return 0;
}
