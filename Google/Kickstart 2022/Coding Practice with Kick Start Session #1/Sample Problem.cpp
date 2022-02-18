#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;cin>>test;
    for(int t=1; t<=test; t++){
        int n, m;cin>>n>>m;
        int candy=0;
        for(int i=0; i<n; i++){
            int x;cin>>x;
            candy += x;
        }
        int gave = candy/m;
        int left = candy - (gave*m);
        cout<<"Case #"<<t<<": "<<left<<endl;
    }
}
