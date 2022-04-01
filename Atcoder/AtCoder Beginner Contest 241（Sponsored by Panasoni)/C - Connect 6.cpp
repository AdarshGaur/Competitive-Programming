// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

string solve(){
	int n;cin>>n;
	string s[n];
	for(auto& i: s)cin>>i;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//horizontal
			if(j+5<n){
				int d=0;
				for(int k=0; k<6; k++){
					d += (s[i][j+k]=='.'?1:0);
				}
				if(d<=2)return "Yes";
			}
			//vertical
			if(i+5<n){
				int d=0;
				for(int k=0; k<6; k++){
					d += (s[i+k][j]=='.'?1:0);
				}
				if(d<=2)return "Yes";
			}
			//diagonal
			if(i+5<n and j+5<n){
				int d=0;
				for(int k=0; k<6; k++){
					d += (s[i+k][j+k]=='.'?1:0);
				}
				if(d<=2)return "Yes";
			}
			// forgot the second diagonal you dumbass
			if(i+5<n and j-5>=0){
				int d=0;
				for(int k=0; k<6; k++){
					d += (s[i+k][j-k]=='.'?1:0);
				}
				if(d<=2)return "Yes";
			}
		}
	}
	return "No";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	cout<<solve()<<endl;
	return 0;
}
