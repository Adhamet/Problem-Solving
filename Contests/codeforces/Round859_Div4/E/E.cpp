#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto ask = [&](int l, int r) {
        std::cout << "? " << (r - l + 1) << ' ';
        for (int i = l; i <= r; i++) std::cout << i << ' ';
        std::cout << '\n';
        std::cout.flush();
    };

    int t; 
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::vector<i64> a(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }

        int l = 1, r = n;

        while (l < r) {
            int mid = (l + r) / 2;

            ask(l, mid);

            i64 feedback;
            std::cin >> feedback;

            i64 expected = pref[mid] - pref[l - 1];

            if (feedback != expected) r = mid;
            else l = mid + 1;
        }

        std::cout << "! " << l << '\n';
        std::cout.flush();
    }

    return 0;
}

