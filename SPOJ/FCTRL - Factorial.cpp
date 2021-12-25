#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t; cin>>t;
	
	while(t--){
		int ans=0;
		ll N;
		cin>>N;
		ll temp=1;
		for(int i=1;temp>0;i++){
			temp=N/pow(5, i);
			ans+=temp ;
			
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}