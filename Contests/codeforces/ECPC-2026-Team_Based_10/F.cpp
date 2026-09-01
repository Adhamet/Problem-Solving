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

    int n;  std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        std::cin >> a >> c >> b;
        v[i] = a * 60 + b;
    }

    if (n == 1) std::cout << 2 << '\n';
    else if (n == 2) {
        if (v[1] - v[0] <= 10) std::cout << 1 << '\n';
        else std::cout << 2 << '\n';
    } else {
        bool f1 = false;
        for (int i = 0; i < n - 2; i++)
            if (v[i + 2] - v[i] <= 10) f1 = true;

        bool f2 = false;
        for (int i = 0; i < n - 1; i++)
            if (v[i + 1] - v[i] <= 10) f2 = true;

        if (f1) std::cout << 0 << '\n';
        else if (f2) std::cout << 1 << '\n';
        else std::cout << 2 << '\n';
    }

    return 0;
}
