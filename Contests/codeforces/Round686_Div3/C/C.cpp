#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)2e5+5;

std::vector<int> a[MXN];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        for (int i = 0; i < n + 2; i++) a[i].clear();

        std::set<int> st;
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            st.insert(x);
            a[x].push_back(i);
        }

        int ans = INT_MAX;
        for (auto x: st) {
            int cur = 0;

            if ((int)a[x].size() == 0) continue;

            if (a[x][0] != 0) cur++;
            for (int i = 1; i < (int)a[x].size(); i++) {
                if (a[x][i] - a[x][i-1] > 1) {
                    cur++;
                }
            }
            if (a[x].back() != n-1) cur++;

            ans = std::min(ans, cur);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
