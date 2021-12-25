#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define mod 1000000007  //10^9 +7
#define MAX 100001      //10^5 +1
#define PI (3.141592653589)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int times; cin >> times;
    while (times--)
    {
        int n; cin >> n;
        int result = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                result -= result / i;
            }
        }
        if (n > 1) {
            result -= result / n;
        }
        cout << result << endl;
    }
    return 0;
}