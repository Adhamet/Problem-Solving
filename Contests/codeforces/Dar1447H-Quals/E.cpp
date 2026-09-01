#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int tot = std::accumulate(a.begin(), a.end(), 0);
    if (tot == 0) std::cout << "NO\n";
    else {
        std::unordered_multiset<int> ms(a.begin(), a.end());
        int ctot = *ms.begin();
        for (auto it = ms.begin(); std::next(it) != ms.end(); it++) {
            auto it2 = std::next(it);
            if (ctot + *it2 == 0) {
                ms.erase(ms.find(*it2));
                ms.insert(*it2);
            }
            ctot += *it2;
        }

        std::cout << "YES\n";
        for (auto x: ms) {
            std::cout << x << ' ';
        }
    }

    return 0;
}
