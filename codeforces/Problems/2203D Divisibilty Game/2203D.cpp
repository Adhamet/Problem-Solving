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
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int mxB = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        mxB = std::max(mxB, b[i]);
    }

    std::vector<int> uqA = a;
    std::sort(uqA.begin(), uqA.end());
    uqA.erase(std::unique(uqA.begin(), uqA.end()), uqA.end());

    i64 lcmA = 1;
    for (int x: uqA) {
        lcmA = std::lcm(lcmA, (i64)x);
        if (lcmA > mxB) {
            lcmA = mxB + 1;
            break;
        }
    }

    std::vector<bool> accessible(mxB + 1, false);
    for (int x: uqA) {
        if (x > mxB) continue;
        for (int mul = x; mul <= mxB; mul += x) {
            accessible[mul] = true;
        }
    }

    int c1 = 0;
    int cnt = 0;

    for (int x: b) {
        if (x % lcmA == 0) c1++;
        if (accessible[x]) cnt++;
    }

    int c2 = m - cnt; // Only Bob can pick (divisible by NO a_i)
    int c3 = cnt - c1; // Both can pick (divisible by SOME but not all a_i)
    if (c1 + (c3+1) / 2 > (c2 + c3) / 2) std::cout << "Alice\n";
    else std::cout << "Bob\n";
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
