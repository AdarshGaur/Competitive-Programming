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
    ll t; cin >> t;
    ll stamp, f;
    for (ll i = 1; i <= t; i++) {
        cin >> stamp;
        cin >> f;
        ll arr[f];
        for (ll j = 0; j < f; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + f, greater<ll>());
        ll times = 0;
        bool possible = false;
        for (ll j = 0; j < f; j++) {
            stamp = stamp - arr[j];
            times++;
            if (stamp <= 0) {
                possible = true;
                break;
            }
        }
        cout << "Scenario #" << i << ":" << endl;

        if (possible == true) {
            cout << times << endl;
        }
        else {cout << "impossible" << endl;}

        if (i != t) {cout << endl;}
    }
    return 0;
}