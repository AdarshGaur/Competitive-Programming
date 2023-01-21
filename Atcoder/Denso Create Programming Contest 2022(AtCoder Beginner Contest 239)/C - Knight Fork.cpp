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
	int x1, x2, y1, y2;
	cin>>x1>>y1>>x2>>y2;
	int x[] = {-1, 1, -1, 1, -2, 2, -2, 2};
	int y[] = {-2, -2, 2, 2, 1, 1, -1, -1};
	int px[8], py[8];
	string ans = "No";
	for(int i=0; i<8; i++){
		px[i] = x1+x[i];
		py[i] = y1+y[i];
	}
	for(int i=0; i<8; i++){
		if( abs(px[i]-x2) == 1){
			if(abs(py[i]-y2) == 2){
				ans="Yes";
				break;
			}
		}else if( abs(px[i]-x2) == 2){
			if( abs(py[i]-y2) == 1){
				ans="Yes";
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
