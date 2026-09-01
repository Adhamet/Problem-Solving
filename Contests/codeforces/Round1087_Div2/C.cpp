#include <bits/stdc++.h>

// -- Don't use with doubles -----------
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// -------------------------------------
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void ask(int i, int j) {
    std::cout << "? " << i << ' ' << j << '\n';
    std::cout.flush();
}

void solve() {
    int n;  std::cin >> n;

    for (int i = 1; i <= 2 * n - 2; i += 2) {
        ask(i, i + 1);
        int input;
        std::cin >> input;
        if (input == 1) {
            std::cout << "! " << i << '\n';
            std::cout.flush();
            return;
        }
    }

    ask(2*n-1, 1);
    int input;
    std::cin >> input;
    if (input == 1) {
        std::cout << "! " << 2*n-1 << '\n';
        std::cout.flush();
        return;
    }

    ask(2*n-1, 2);
    std::cin >> input;
    if (input == 1) {
        std::cout << "! " << 2*n-1 << '\n';
        std::cout.flush();
        return;
    }

    std::cout << "! " << 2*n << '\n';
    std::cout.flush();
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // array a of len 2n, each given integer from 1 to n
    // exists once, rest 0.
    // if (a[i] == a[j]) response = 0, (works only on 0s)
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
