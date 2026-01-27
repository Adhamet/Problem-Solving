#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, h, l;    std::cin >> n >> h >> l;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        int smol, big;
        smol = std::min(h,l);
        big = std::max(h,l);

        int tkSmol = 0, tkBig = 0;
        std::vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (a[i] > smol) {
                vis[i] = true;
                tkBig++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (tkSmol == tkBig) break;
            if (vis[i]) continue;

            if (a[i] <= smol) {
                vis[i] = true;
                tkSmol++;
            }
        }

        int takes = 0, ans = tkSmol;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vis[i] = true;
            takes++;
            if (takes % 2 == 0) {
                ans += 1;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
