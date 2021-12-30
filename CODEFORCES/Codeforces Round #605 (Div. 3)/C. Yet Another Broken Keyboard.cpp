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
    
    int n, k;cin>>n>>k;
    string s;cin>>s;
    char ch[k];
    for(int i=0; i<k; i++){
		cin>>ch[i];
	}
	vector<string> v;
	string temp="";
	for(int i=0; i<n; i++){
		for(auto c:ch){
			if(s[i]==c){
				goto next;
			}
		}
		v.push_back(temp);
		temp="";
		continue;
		next:
			temp += s[i];
	}
	v.push_back(temp);
	int ans=0;
	for(auto j:v){
		int x = (int)j.size(); 
		ans += (x*(x+1))/2;
	}
	cout<<ans<<endl;
    return 0;
}
