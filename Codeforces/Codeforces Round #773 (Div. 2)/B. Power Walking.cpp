// Author : Adarsh Gaur 
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	int a[n];
	set<int> s;
	for(int i=0; i<n; i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	int res = s.size();
	for(int i=1; i<=n; i++){
		if(i > res)res+=1;
		cout<<res<<" ";
	}
	cout<<"\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
