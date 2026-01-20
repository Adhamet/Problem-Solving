#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n, m, h;    std::cin >> n >> m >> h;
        std::vector<i64> a(n+1);
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        std::vector<i64> org;
        org = a;

        std::unordered_set<int> ops;
        while (m--) {
            int idx;
            i64 cost;
            std::cin >> idx >> cost;

            if (ops.find(idx) == ops.end()) {
                ops.insert(idx);
            }
            a[idx] += cost;

            if (a[idx] > h) {
                for (auto op: ops) {
                    a[op] = org[op];
                }
                ops.clear();
            }
        }

        for (int i = 1; i <= n; i++) std::cout << a[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
