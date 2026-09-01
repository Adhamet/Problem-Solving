#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, k;   std::cin >> n >> k;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        int hiredBitMask = 0;
        i64 ans = 0;
        std::vector<bool> vis(n, false);
        for (int bit = k - 1; bit >= 0; bit--) {
            bool canFill = true;
            for (int i = 0; i < n; i++) {
                if (!(a[i] & (1 << bit))) {
                    if (vis[i]) {
                        canFill = false;
                        break;
                    }
                }
            }

            if (canFill) {
                ans += (1LL << bit);
                hiredBitMask |= (1 << bit);
                for (int i = 0; i < n; i++) {
                    if (!(a[i] & (1 << bit))) {
                        vis[i] = true;
                        a[i] |= (1 << bit);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool safeOp = false;
                for (int bit = 0; bit < k; bit++) {
                    if (((a[i] & (1 << bit)) && !(hiredBitMask & (1 << bit))) || !(a[i] & (1 << bit))) {
                        vis[i] = true;
                        safeOp = true;
                        break;
                    }
                }
                
                if (!safeOp) {
                    for (int bit = 0; bit < k; bit++) {
                        if (hiredBitMask & (1 << bit)) {
                            ans -= (1LL << bit);
                            hiredBitMask &= ~(1 << bit);
                            break;
                        }
                    }
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
