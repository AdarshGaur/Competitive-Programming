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

//int const INF = 2e18;
//int const mod = 1e9 +7;
//int const mod = 998244353;
//int const N = 1e5 + 7;

pii ask(string s){
	cout<<s<<endl;
	cout.flush();
	pii p;
	cin>>p.ff>>p.ss;
	return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    string pos;
    for(char i = '0'; i<='9' ; i++){
		string a(4, i);
		pii g = ask(a);
		if(g.ff>0){
			pos += i;
		}
		if(pos.size() == 4){
			break;
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				for(int l=0; l<4; l++){
					if(i==j or i==k or i==l or
						j==k or j==l or k==l){
							continue;
					}
					string check(1, pos[i]);
					check += pos[j];
					check += pos[k];
					check += pos[l];
					pii p = ask(check);
					if(p.ff == 4 and p.ss == 0)exit(0);
				}
			}
		}
	}
    return 0;
}
