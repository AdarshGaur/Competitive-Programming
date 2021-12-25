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
    int t;cin>>t;while(t--){
        int N;
        cin>>N;
        int m=1;
        ll x, temp=0;
        int arr[200]={0};
        arr[0]=1;
        for(int i=2; i<=N; i++){
            for(int j=0; j<m; j++){
                x = (arr[j]*i) + temp;
                temp = x/10;
                arr[j] = x%10;
            }
            while(temp!=0){
                arr[m] = temp%10;
                m++;
                temp/= 10;
            }
        }
        for(int i=m-1; i>=0; i--){
            cout<<arr[i];
        }
        if(t!=0){cout<<endl;}
    }
    return 0;
}