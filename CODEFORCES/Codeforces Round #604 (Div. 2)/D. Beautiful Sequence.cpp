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



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
	int a, b, c, d, tb, tc;
	string ans="YES";
	cin>>a>>b>>c>>d;
	if(a>b or d>c)ans="NO";
	tb = b-a;
	tc = c-d;
	int difcd = abs(tc-tb);
	if(difcd>1)ans="NO";
	if((a==b and b==0) or (c==d and c==0)){
		if(abs(c-d)>1 or abs(a-b)>1){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		ans = "";
		for(int i=0; i<min(a,b); i++){
			ans += "01";
		}
		if(a > b){
			ans+="0";
		}else if(a < b){
			ans = "1" + ans;
		}
		for(int i=0; i<min(c,d); i++){
			ans += "23";
		}
		if(c > d){
			ans+="2";
		}else if(c < d){
			ans = "3" + ans;
		}
		for(auto i: ans){
			cout<<i<<" ";
		}
		return 0;
	}
	cout<<ans<<endl;
	if(ans=="YES"){
		ans = "";
		for(int i=0; i<a; i++){
			ans += "01";
		}
		string temp;
		for(int i=0; i<d; i++){
			temp += "32";
		}
		reverse(temp.begin(), temp.end());
		for(int i=0; i<min(tc, tb); i++){
			ans += "21";
		}
		if(tc > tb)
			temp += "2";
		if(tb > tc)
			cout<<"1 ";
		ans += temp;
		for(auto i: ans){
			cout<<i<<" ";
		}
	}
    return 0;
}
