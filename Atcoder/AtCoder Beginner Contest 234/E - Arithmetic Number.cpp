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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


int solve(int x){
	set<int> s;
	for(int i=1; i<=9; i++){
		for(int j=-9; j<9; j++){
			string res;
			int dg = i;
			for(int k=0; k<18; k++){
				res += (dg+'0');
				s.insert(ii(stoll(res)));
				dg += j;
				if(dg<0 or dg>9)
					break;
			}
		}
	}
	return *s.lower_bound(x);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        int x;cin>>x;
        cout << solve(x) <<endl;
    }
    return 0;
}
