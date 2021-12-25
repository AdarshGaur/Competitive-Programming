#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;while(t--){
        ll N;cin>>N;
        ll ans;
        ans = (ll)((N*(N+2)*((2*N)+1))/8);
        cout<<ans;
        if(t!=0){cout<<"\n";}
    }
    return 0;
}