#include <bits/stdc++.h>
#include <iomanip>
#include <ios>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const long double PI = acos(-1);

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    long double x;
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(20) << PI * (x/2) * (x/2) << '\n';

    return 0;
}
