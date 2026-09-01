#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<std::array<i64,3>> v(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                std::cin >> v[i][j];
            }
        }

        std::vector<std::set<int>> sts(n);
        sts.reserve(n);

        int stsIdx = 0;
        for (int i = 0; i < n; i++) {
            if (sts[stsIdx].empty()) sts[stsIdx].insert(i);
            for (int j = 0; j < n; j++) {
                i64 a = (v[i][0] - v[j][0]);
                i64 b = (v[i][1] - v[j][1]);
                i64 c = (v[i][2] - v[j][2]);

                i64 discriminant = b*b - 4*a*c;

                // debug(i,j,discriminant);
                if ((a != 0 && discriminant < 0) || (a==0 && b==0 && c!=0)) {
                    sts[stsIdx].insert(j);        
                }
            }

            if (!sts[stsIdx].empty()) stsIdx++;
        }

        // debug(sts);

        std::vector<int> sizes(n, 0);
        for (auto st: sts) {
            if ((int)st.empty()) break;
            for (auto x: st) sizes[x] = (int)st.size();
        }

        for (auto x: sizes) std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}
