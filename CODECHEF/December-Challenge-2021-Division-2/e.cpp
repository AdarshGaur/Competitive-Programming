// Author : Adarsh Gaur 

// Problem Name : Squares Counting
// Problem url : https://www.codechef.com/DEC21B/problems/GRIDSQRS

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n;cin>>n;
	int mat[n][n], dp1[n][n], dp2[n][n]; // dp1 - downwards , dp2 - rightward
	for(int j=0; j<n; j++){
		string s;cin>>s;
		for(int i=0; i<n; i++){
			mat[j][i] = s[i]-'0';
		}
	}
	/// precompute the dp matrices
	for(int i=0; i<n; i++){
		dp1[n-1][i] = mat[n-1][i];
	}
	for(int i=n-2; i>=0; i--){
		for(int j=0; j<n; j++){
			dp1[i][j] = dp1[i+1][j] + 1;
			if(!mat[i][j])dp1[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){
		dp2[i][n-1] = mat[i][n-1];
	}
	for(int j=n-2; j>=0; j--){
		for(int i=0; i<n; i++){
			dp2[i][j] = dp2[i][j+1]+1;
			if(!mat[i][j])dp2[i][j]=0;
		}
	}
	int frames=0;
	for(int i=0; i<n; i++){ // x coordinate
		for(int j=0; j<n; j++){ // y coordinate 
			if(!mat[i][j])continue;
			int mx = max(i,j);
			for(int k=0; k<n-mx; k++){ // side of the square
				if(dp1[i][j] > k and dp2[i][j] > k
					and dp1[i][j+k] > k and
					dp2[i+k][j] > k)frames++;
			}
		}
	}
	cout<<frames<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
