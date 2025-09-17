#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;	std::cin >> t;
    while (t--) {
        int n;	std::cin >> n;
        std::vector<int> a(n), zeros;
        std::vector<bool> exists(n + 1, false);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] == 0) zeros.push_back(i);
            else exists[a[i]] = true;
        }

        int l = n, r = -1;
        if ((int)zeros.size() == 1) {
            int cur = zeros[0];
            bool must = !exists[cur + 1];
            for (int i = 0; i < n; i++) if ((a[i] != 0 && a[i] != i + 1) || (a[i] == 0 && !must))
			l = std::min(l, i), r = std::max(r, i);
        } else for (int i = 0; i < n; i++) if ((a[i] != 0 && a[i] != i + 1) || a[i] == 0) {
                  l = std::min(l, i), r = std::max(r, i);
        }

        std::cout << (r == -1? 0: r - l + 1) << '\n';
    }

    return 0;
}

