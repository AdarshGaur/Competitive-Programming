#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;while(t--){
        long long n, a, sum, b, l, d;
        cin>>b>>l>>sum;
        n=(sum*2)/(b+l);
        d=((l-b)/(n-5));
        a=b-(d*2);
        cout<<n<<"\n";
        for(long long i=0; i<n; i++){
            cout<<a+(i*d);
            if(i!=n-1){cout<<" ";}
        }
        if(t!=0){cout<<"\n";}
    }
    return 0;
}