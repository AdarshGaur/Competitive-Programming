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
    unsigned ll num, sum=0;
    unsigned int digit, t=0;
    cin>>num;
    while(num!=1){
        sum=0;
        while(num!=0)
        {
            digit = num%10;
            num/=10;
            sum+=(digit*digit);
        }
        num = sum;
        t++;
        if(num==37){
            cout<<"-1";
            return 0;
        }
    }
    cout<<t;
    return 0;
}