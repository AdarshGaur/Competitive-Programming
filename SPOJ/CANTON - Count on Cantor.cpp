#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 1000001
#define PI 3.14159265

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int times; cin >> times; while (times--) {
        unsigned ll n, sum = 0;
        cin >> n;
        unsigned i, upper, lower;
        for (i = 1; i < n; i++) {
            sum += i;
            if (sum >= n) {
                sum -= i;
                sum = n - sum;
                break;
            }
        }
        if (i % 2 == 0) {
            upper = sum;
            lower = i - sum + 1;
        }
        else {
            lower = sum;
            upper = i - sum + 1;
        }
        cout << "TERM " << n << " IS " << upper << "/" << lower << endl;
    }
    return 0;
}