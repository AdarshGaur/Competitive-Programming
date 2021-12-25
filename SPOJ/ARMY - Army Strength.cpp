#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 100001

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string blank;
    int t;cin>>t;while(t--){
        getline(cin, blank);
        int NG, NM;
        cin>>NG>>NM;
        int godzilla[NG];
        int MechaG[NM];
        for(ll i=0; i<NG; i++){
            cin>>godzilla[i];
        }
        for(ll i=0; i<NM; i++){
            cin>>MechaG[i];
        }
        sort(godzilla, godzilla+NG);
        sort(MechaG, MechaG+NM);

        if(godzilla[NG-1]>=MechaG[NM-1]){
            cout<<"Godzilla";
        }
        else{
            cout<<"MechaGodzilla";
        }

        if(t!=0){cout<<endl;}
    }
    return 0;
}