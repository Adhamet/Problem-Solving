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
        int n;          std::cin >> n;
        std::string s;  std::cin >> s;

        std::vector<int> prefOp(n), suffClos(n);
        prefOp[0] = 1, suffClos[n-1] = 1;
        for (int i = 1; i < n; i++)
            prefOp[i] = prefOp[i-1] + (s[i] == '(');
        for (int i = n - 2; i >= 0; i--)
            suffClos[i] = suffClos[i+1] + (s[i] == ')');

        std::vector<int> nxt(n, -1);
        {
            std::vector<int> vs;
            for (int i = 0; i < n; i++) {
                if (s[i] == ')') {
                    vs.push_back(i);
                } else if (!vs.empty()) {
                    for (auto v: vs) nxt[v] = i;
                    vs.clear();
                }
            }
        }

        i64 ans = -1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == ')') {
                int j = (i + 1 < n? nxt[i]: -1);
                if (j == -1) continue;
                if (suffClos[j+1] >= prefOp[i]+1) {
                    ans = std::max(ans, (2LL * (prefOp[i]+1)));
                }
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
