// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tuple<int,int,int> item;

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


int solve(){
	int a, b;cin>>a>>b;
	if(a==b)return 0;
	if(a>b)swap(a,b);
	int x=1;
	while(a<b){
		a += x++;
	}
	if((b-a)%2==0)return x-1;
	a += x++;
	if((b-a)%2==0)return x-1;
	return x;
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
