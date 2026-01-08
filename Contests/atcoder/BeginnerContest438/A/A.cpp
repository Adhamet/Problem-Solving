#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int days, f;
    std::cin >> days >> f;

    int i = f;
    while (i + 7 <= days) i += 7;
    if (i <= days) i += 7;
    i -= days;

    return std::cout << i, 0;
}
