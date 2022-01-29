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


void solve(){
	int n, k;cin>>n>>k;
	string s;cin>>s;
	deque<int> indx;
	for(int i=0; i<n; i++){
		if(s[i]=='0'){
			indx.push_back(i);
		}
	}
	for(int i=0; i<n; i++){
		if(s[i]=='0'){
			indx.pop_front();
		}else{
			int nx = INF;
			if(!indx.empty()){
				nx = indx.front();
				indx.pop_front();
			}
			assert(nx>i);
			int dif = nx - i;
			if(k>=dif){
				assert(nx>i and nx<n);
				swap(s[i],s[nx]);
				k -= dif;
			}else if(nx!=INF){
				assert(i+k<nx and nx<n);
				dif -= k;
				i += dif;
				swap(s[i], s[nx]);
				break;
			}
		}
	}
	cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
