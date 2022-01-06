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
	map<string, int> mp;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>words[i];
		if(words[i].front() =='0'){
			a[i]=0;
		}else{
			a[i]=2;
		}
		if(words[i].back() == '0'){
			a[i]+=0;
		}else{
			a[i]+=1;
		}
		mp[words[i]]++;
	}
	int zo=0, oz=0, oo=0, zz=0;
	for(auto i:a){
		if(i==1){
			zo++;
		}else if(i==2){
			oz++;
		}else if(i==0){
			zz++;
		}else{
			oo++;
		}
	}
	int rev=n, t=0;
	if(oz+zo>0){
		if(abs(oz-zo)<2){
			rev=0;
		}else if(oz<zo){
			rev = zo-oz;
			t = 1;
		}else{
			rev = oz-zo;
			t = 2;
		}
	}else{
		if(zz==0 or oo==0){
			rev = 0;
		}else{
			rev = -1;
		}
	}
	vi ans;
	if(rev>0){
		for(int i=0; i<n; i++){
			if(a[i]==t){
				string k = words[i];
				reverse(k.begin(), k.end());
				if(mp.count(k) == 0){
					ans.push_back(i);
				}
			}
		}
		rev/=2;
	}
	if(ii(ans.size()) < rev){
		rev=-1;
	}
	cout<<rev<<endl;
	if(rev==-1)return;
	for(int i=0; i<rev; i++){
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
