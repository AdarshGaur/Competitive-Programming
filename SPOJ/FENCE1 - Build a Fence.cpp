#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mod 1000000007
#define MAX 10001
#define PI 3.1415926
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true)
    {
        double l;
        cin>>l;
        if(l==0){
            return 0;
        }
        double area=l*l;
        area = area/(2*PI);
        printf("%.2lf\n", area);
    }
    return 0;
}