#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        ms.insert(x);
    }

    bool done = false;
    for (int i = 1; i <= n; i++) {
        auto it = ms.lower_bound(i);
        if (it == ms.end()) {
            done = true;
            std::cout << i-1;
            break;
        }
        ms.erase(it);
    }

    if (!done) std::cout << n;

    return 0;
}
