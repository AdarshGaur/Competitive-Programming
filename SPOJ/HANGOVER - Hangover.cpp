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
    while(true){
        float sum;
        cin>>sum;
        if(sum==0.00){
            return 0;
        }
        else{
            cout<<endl;
        }
        int n=0, i=2;
        float var=0;
        while(sum>var){
            var= var + (1.00/i);
            i++;
            n++;
        }
        cout<<n<<" card(s)";
    }
    return 0;
}