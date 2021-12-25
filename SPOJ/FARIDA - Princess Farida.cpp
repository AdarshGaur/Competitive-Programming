#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define mod 1000000007  //10^9 +7
#define MAX 100001      //10^5 +1
#define PI (3.141592653589)


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll times; cin >> times;
    for (int j = 0; j < times; j++)
    {
        ll n;
        cin >> n;
        if (n == 0) {
            cout << "Case " << j + 1 << ": 0" << endl;
            continue;
        }
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll dp[n] = {0};
        dp[0] = arr[n - 1];
        if (n == 1) {
            cout << "Case " << j + 1 << ": " << dp[0] << endl;
            continue;
        }
        if (n > 1) {
            dp[1] = arr[n - 2];
        }
        if (n > 2) {
            dp[2] = arr[n - 3] + arr[n - 1];
        }
        for (ll i = 3; i < n; i++) {
            if (dp[i - 2] < dp[i - 3]) {
                dp[i] = arr[n - i - 1] + dp[i - 3];
            } else {
                dp[i] = arr[n - i - 1] + dp[i - 2];
            }
        }
        if (dp[n - 1] > dp[n - 2]) {
            cout << "Case " << j + 1 << ": " << dp[n - 1] << endl;
        } else {
            cout << "Case " << j + 1 << ": " << dp[n - 2] << endl;
        }
    }
    return 0;
}