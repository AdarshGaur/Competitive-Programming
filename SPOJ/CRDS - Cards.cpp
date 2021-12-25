#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000007
#define MAX 100001

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t; while (t--) {
        unsigned ll n;
        cin >> n;
        unsigned ll sum;
        sum = 3 * (n * n) + n;
        sum /= 2;
        sum = sum % mod;
        cout << sum << endl;
    }
    return 0;
}