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


string solve(){
	string a, s, ans="";
	cin>>a>>s;
	int j=a.size()-1, i=s.size()-1;
	for(;i>=0 and j>=0; i--, j--){
		if( a[j] == s[i]){
			ans += "0";
		}else if(a[j] < s[i]){
			char c  = s[i]-a[j];
			ans += (to_string(c)).at(0);
		}else if(i>0){
				int x = 10*(s[i-1]-'0');
				x += (s[i]-'0') - (a[j]-'0');
				if(x>9 or x<0)
					return "-1";
				string k = to_string(x);
				ans += k[0];
				i--;
		}else return "-1";
	}
	while(i>=0)ans.push_back(s[i--]);
	if(j>=0)return "-1";
	while(ans.back()=='0' and ans.size()>0)
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	return ans;
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
        cout<< solve() <<endl;
    }

    return 0;
}
