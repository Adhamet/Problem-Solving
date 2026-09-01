#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // only i shifts for each prefix i until things are back
    // to normal, so there are i - 1 diff variations of pref i
    // each ans[i] neednt exceed i-1.
    // n <= 2e3, solution can be O(n^2 * logn)
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
