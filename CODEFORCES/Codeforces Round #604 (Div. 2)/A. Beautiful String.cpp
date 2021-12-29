// Author : Adarsh Gaur 

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
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;
string s;
int n;

void assignchar(int prev, int cur, int next){
	if(next < n and next>=0){
		if(s[prev]=='a'){
			if(s[next]=='b'){
				s[cur]='c';
			}else{
				s[cur]='b';
			}
		}else if(s[prev]=='b'){
			if(s[next]=='a'){
				s[cur]='c';
			}else{
				s[cur]='a';
			}
		}else{
			if(s[next]=='b'){
				s[cur]='a';
			}else{
				s[cur]='b';
			}
		}
	}else{
		if(s[prev]=='a'){
			s[cur]='b';
		}else{
			s[cur]='a';
		}
	}
}

void solve(){
	cin>>s;
	n = (int)s.size();
	int pos=0;
	for(int i=0; i<n; i++){
		if(s[i]!='?'){
			pos=i;
			break;
		}
	}
	for(int i=pos+1; i<n; i++){
		if(s[i]=='?')assignchar(i-1,i,i+1);
	}
	for(int i=pos; i>=0; i--){
		if(s[i]=='?')assignchar(i+1,i,i-1);
	}
	for(int i=1; i<n; i++){
		if(s[i]==s[i-1]){
			s="-1";
			break;
		}
	}
	cout<<s<<endl;
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
