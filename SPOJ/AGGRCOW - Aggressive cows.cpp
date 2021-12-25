#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 1000000
#define PI 3.14159265

using namespace std;

ll n, c;
ll arr[MAX];

bool canbe(ll m) {
    int cow_placed = 1, last_pos = arr[0];
    for (ll i = 0; i < n; i++) {
        if ((arr[i] - last_pos) >= m) {
            if (++cow_placed == c) {
                return true;
            }
            last_pos = arr[i];
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll times; cin >> times; while (times--) {
        cin >> n >> c;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        ll high = arr[n - 1], low = 0, mid, pos = 0;
        while (high >= low) {
            mid = (high + low) / 2;
            if (canbe(mid)) {
                low = mid + 1;
                pos = mid;
            }
            else {
                high = mid - 1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}