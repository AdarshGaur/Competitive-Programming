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
	int n;cin>>n;
	int a[n];
	set<int> filled, left;
	for(int i=0; i<n; i++){
		cin>>a[i];
		left.insert(i+1);
	}
	int b[n] = {0};
	int k=0;
	for(int i=0; i<n; i++){
		if(filled.find(a[i])==filled.end()){
			b[i] = a[i];
			k++;
			filled.insert(a[i]);
			left.erase(a[i]);
		}
	}
	left.insert(n+1);
	for(int i=0; i<n; i++){
		if(b[i]==0){
			int x = *left.begin();
			left.erase(left.begin());
			if(x == i+1){
				b[i] = *left.begin();
				left.erase(left.begin());
				left.insert(x);
			}else{
				b[i] = x;
			}
		}
	}
	if( *left.begin() != n+1){
		for(int i=0; i<n; i++){
			if(b[i] == n+1){
				b[i] = *left.begin();
				for(int j=0; j<n; j++){
					if( a[i] == b[j]){
						swap(b[j], b[i]);
						break;
					}
				}
				break;
			}
		}		
	}
	cout<<k<<endl;
	for(int i:b){
		cout<<i<<" ";
	}
	cout<<endl;
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
