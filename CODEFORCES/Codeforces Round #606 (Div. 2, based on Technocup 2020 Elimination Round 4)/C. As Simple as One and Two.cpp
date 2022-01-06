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
	string s;
	cin>>s;
	int n = s.size();
	vi ans;
	if(n<3){
		goto end;
	}
	for(int i=0; i<n; i++){
		if(i+2<n){
			if(s[i]=='o' and s.substr(i,3)=="one"){
				if(i>0){
					if(s[i-1]=='o'){
						ans.push_back(i+1);
						s[i+1]='x';
					}else{
						ans.push_back(i);
						s[i]='x';
					}
				}else{
					ans.push_back(i);
					s[i]='x';
				}
			}
		}
		if(i>1){
			if(s[i]=='o' and s.substr(i-2,3)=="two"){
				if(i<n-1){
					if(s[i+1]=='o'){
						ans.push_back(i-1);
						s[i-1]='x';
					}else{
						ans.push_back(i);
						s[i]='x';
					}
				}else{
					ans.push_back(i);
					s[i]='x';
				}
			}
		}
	}
	end:
	cout<<ans.size()<<endl;
	for(auto i:ans){
		cout<<i+1<<" ";
	}
	cout<<endl;
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
