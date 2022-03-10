// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,cnt=0;
	string s;
	cin >> n >> s;
	for(auto i:s){
		if(i=='0'){
			cnt++;
		}
	}
	if(cnt&1 && cnt>1){
		s = "ALICE";
	}else{
		s = "BOB";
	}
	cout<<s<<endl;
}

signed main()
{
    int times;cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
