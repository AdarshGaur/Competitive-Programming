#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100001
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;while(t--){
        int N;
        cin>>N;
        int men_hotness[N];
        int women_hotness[N];
        for(int i=0; i<N; i++){
            cin>>men_hotness[i];
        }
        for(int i=0; i<N; i++){
            cin>>women_hotness[i];
        }
        sort(men_hotness, men_hotness + N);
        sort(women_hotness, women_hotness + N);

        ll ans=0;

        for(int i=0; i<N; i++){
            ans += (men_hotness[i]*women_hotness[i]);
        }
        cout<<ans;

        if(t!=0){
            cout<<endl;
        }
    }
    return 0;
}