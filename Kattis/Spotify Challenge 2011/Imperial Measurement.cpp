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


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(10);
    int n=8;
    vector<string> full = {"thou", "inch", "foot", "yard", "chain", "furlong", "mile", "league"};
    vector<string> acronym = {"th", "in", "ft", "yd", "ch", "fur", "mi", "lea"};
    vector<int> conversion = {1, 1000, 12, 3, 22, 10, 8, 3};
    int ans, start, end;
    string from, to, in;
    cin>>ans>>from>>in>>to;
    int p1 =  find(full.begin(), full.end(), from) - full.begin();
    int p2 = 	find(acronym.begin(), acronym.end(), from) - acronym.begin();
    if( p1 < n){
		start = p1;
	}else{
		start = p2;
	}
    p1 = find(full.begin(), full.end(), to) - full.begin();
    p2 = find(acronym.begin(), acronym.end(), to) - acronym.begin();
    if(p1<n){
		end = p1;
	}else{
		end = p2;
	}
	int rate=1, tstart=start, tend=end;
	while(tstart!=tend){
		if(tstart>tend){
			rate *= conversion[tstart--];
		}else{
			rate *= conversion[tend--];
		}
	}
	if(start > end){
		cout<<ans*rate<<endl;
	}else{
		cout<< double(ans)/rate <<endl;
	}
    return 0;
}
