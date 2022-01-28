// PBDS - ordered_set

#include <bits/stdc++.h>
using namespace std;
#define int long long


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;

/* 
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero).
    order_of_key()  - Number of items in a set that are strictly smaller than our item.
*/


signed main()
{
    o_set s;
    s.insert(1);
    s.inset(11);
    s.insert(5);
    s.insert(15);
    s.insert(3);
    cout << *(s.find_by_order(2)) << endl;
    cout << s.order_of_key(5) << endl;
    return 0;
}
