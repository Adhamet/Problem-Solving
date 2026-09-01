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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    bool acc = false;
    for (int i = 0; i + 2 < n; i++) {
        if (a[i] == a[i+1] && a[i] == a[i+2]) {
            acc = true;
            break;
        }
    }

    return std::cout << (acc? "Yes": "No"), 0;
}
