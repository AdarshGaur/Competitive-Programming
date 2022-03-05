// Author : Adarsh Gaur 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll x= pow(10,c-1);
        ll y= x;
        
        while(x<(ll)pow(10,a-1)){
            x*=2;
        }
        while(y<(ll)pow(10,b-1)){
            y*=3;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
