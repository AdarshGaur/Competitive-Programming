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
	vector<string> words(n);
	set<string> s;
	bool oo=false, zz=false;
	int zo=0, oz=0;
	for(int i=0; i<n; i++){
		cin>>words[i];
		if(words[i][0]=='0' and words[i].back()=='1'){
			zo++;
		}else if(words[i][0]=='1' and words[i].back()=='0'){
			oz++;
		}else if(words[i][0]=='0' and words[i].back()=='0'){
			oo=true;
		}else{
			zz=true;
		}
		s.insert(words[i]);
	}
	int res = 0;
	string cc = "01";
	if(oo and zz and oz==0 and zo==0){
		cout<<-1<<endl;
		return;
	}else if(oz > zo+1){
		res = oz-zo;
		cc = "10";
	}else if(zo > oz+1){
		res = zo-oz;
	}
	res/=2;
	vi ans;
	for(int i=0; i<n; i++){
		if(cc[0]==words[i][0] and cc[1]==words[i].back()){
			string k = words[i];
			reverse(k.begin(), k.end());
			if(s.find(k) == s.end()){
				ans.push_back(i);
			}
		}
	}
	if(ii(ans.size()) < res){
		res=-1;
	}
	cout<<res<<endl;
	for(int i=0; i<res; i++){
		cout<<ans[i]+1<<" ";
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
