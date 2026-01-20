#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q;  std::cin >> q;

    int pow3[10];   pow3[0] = 1;
    for (int i = 1; i < 10; i++) pow3[i] = pow3[i-1] * 3;

    while (q--) {
        int n;  std::cin >> n;

        int msk = 1<<10;
        i64 ans = INT_MAX;
        for (int curmsk = 0; curmsk < msk; ++curmsk) {
            int curval = 0;
            for (int i = 0; i < 10; i++) {
                if (curmsk & (1<<i)) {
                    curval += pow3[i];
                }
            }
            if (curval >= n && ans > curval) ans = curval;
        }

        std::cout << ans << '\n';
    }

    return 0;
}

