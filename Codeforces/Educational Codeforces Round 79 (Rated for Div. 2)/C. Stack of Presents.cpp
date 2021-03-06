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


void solve(){
	int n, m;cin>>n>>m;
	int a[n], b[m];
	for(int &i: a)cin>>i;
	for(int &i: b)cin>>i;
	set<int> s;
	int t=0, j=0;
	for(int i=0; i<m; i++){
		if(s.find(b[i])!=s.end()){
			t++;
			s.erase(s.find(b[i]));
		}else{
			while(a[j]!=b[i]){
				s.insert(a[j++]);
			}
			j++;
			t += 2*(s.size()+1) -1;
		}
	}
	cout<<t<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		//cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
