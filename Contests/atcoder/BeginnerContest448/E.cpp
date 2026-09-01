#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MOD = 10007;
    // int ans = (n / m) % MOD;
    //
    // a way to take modulo, based on the number of digits
    // from left to right do
    // cur(new) = (cur(old) * 10 + d) % MOD;
    // cur(new) = (cur(old) * 10 % mod + d % mod) % MOD;
    //
    // The issue is processing the 1e9 digits, so the above
    // equation is satisfying but we can't just loop 1e9 times
    // where we keep up that recurrence.
    //
    // even if we tried to fill up some string with 18 digits
    // of ci to then stoll and use it, we'll need 1e9/18 operations
    // which is 1e7 or something per pair, and we have K <= 1e5 pairs
    // so at worst case its 1e7 * 1e5 = 1e12
    //
    // 

    return 0;
}
