// Author : Adarsh Gaur 

// Problem Name : Rock Paper Scissors
// Problem url : https://www.codechef.com/DEC21B/problems/ROPASCI

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n;cin>>n;
	string s, c="RPS";
	cin>>s;
	string ans = s;
	int i = n-1;
	char last='?';
	for(int k=0; k<3; k++){
		if(s[i]==c[k]){
			last = c[(k+1)%3];
		}
	}
	i--;
	while(i>=0 and s[i]==s[n-1])i--;
	while(i>=0){
	for(int k=0; k<3; k++)
		if(s[i]==c[k]){
			int x = (k+1)%3;
			if(s[i+1]==s[i]){
				ans[i] = ans[i+1];
			}else if(s[i+1]==c[x]){
				ans[i] = ans[i+1];
				last = ans[i+1];
			}else{
				ans[i] = last;
				last = ans[i+1];
			}
		}
	i--;
	}
	cout<<ans<<endl;
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
