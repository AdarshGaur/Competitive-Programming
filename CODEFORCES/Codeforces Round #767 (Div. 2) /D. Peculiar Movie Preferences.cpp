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
//int const mod = 998244353;
//int const N = 1e5 + 7;


bool ispalin(string s){
	int l=0, h=s.size()-1;
	while(h>l)
		if(s[l++]!=s[h--])return false;
	return true;
}


bool solve(){
	int n;cin>>n;
	string s[n];
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	map<string, int> mp;
	for(int i=0; i<n; i++){
		string r(s[i].rbegin(), s[i].rend());
		if(ispalin(s[i]))return true;
		if(mp.count(r)!=0)return true;
		if(mp.count(r.substr(0,2))!=0)
			if(mp[r.substr(0,2)]==2 or size(r)==2)return true;
		string ss = s[i].substr(0,2);
		if(mp.count(ss)==0)mp[ss] = 4;
		if(mp.count(s[i])==0)mp[s[i]] = 4;
		mp[s[i]] = min(mp[s[i]], ii(s[i].size()));
		mp[ss] = min(mp[ss], ii(s[i].size()));
	}
	return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}
