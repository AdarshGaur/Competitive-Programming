#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans = 0, t;
    scanf("%lld", &t);
    ll arr[t];
    for (ll i = 0; i < t; i++) {
        scanf("%lld", &arr[i]);
        ans ^= arr[i];
    }
    cout << ans;
    return 0;
}