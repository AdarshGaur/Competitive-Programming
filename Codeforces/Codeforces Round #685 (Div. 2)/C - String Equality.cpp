/*

Author : Adarsh Gaur 

*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

//#define fore(i,s,e) for(int i=s; i<e; ++i)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
//#define all(x) (x).begin(), (x).end()
//#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
//#define pb push_back
#define ff first
#define ss second

#define INF 2e18
//const int mod = 1e9 +7;
const int mod = 998244353;

//int()
void solve(){
	int n, k;cin>>n>>k;
	string a, b;
	cin>>a>>b;
	int freqa[26]={0}, freqb[26]={0};
	for(int i=0; i<n; i++){
		freqa[a[i]-'a']++;
		freqb[b[i]-'a']++;
	}
	int carry=0;
	bool pos=true;
	for(int i=0; i<26; i++){
		freqa[i] += carry;
		if(freqa[i] >= freqb[i]){
			carry = freqa[i]-freqb[i];
		}else{
			pos=false;
			break;
		}
		if(carry%k!=0){
			pos=false;
			break;
		}
	}
	if(pos){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    
    int times=1;
    cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}

