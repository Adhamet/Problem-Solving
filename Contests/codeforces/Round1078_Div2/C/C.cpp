#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, k;   std::cin >> n >> k;
        std::vector<std::string> str(k);
        for (int i = 0; i < k; ++i) std::cin >> str[i];

        std::vector<std::vector<bool>> chars(n, std::vector<bool>(26, false));
        for (int col = 0; col < n; col++) {
            for (int ro = 0; ro < k; ro++) {
                chars[col][str[ro][col] - 'a'] = true;
            }
        }

        std::vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (n / i != i) divs.push_back(n/i);
            }
        }
        std::sort(divs.begin(), divs.end());

        std::string ans(n, 'A');
        for (int d: divs) {
            std::vector<char> comp(d, 0);

            bool acc = true;
            for (int r = 0; r < d; r++) {
                std::vector<bool> ok(26, true);

                for (int idx = r; idx < n; idx += d) {
                    for (int l = 0; l < 26; l++) {
                        if (!ok[l] || !chars[idx][l])
                            ok[l] = false;
                    }
                }

                char taken = 'A';
                for (int l = 0; l < 26; l++) {
                    if (ok[l]) {
                        taken = 'a' + l;
                        break;
                    }
                }

                if (taken == 'A') {
                    acc = false;
                    break;
                }

                comp[r] = taken;
            }

            if (acc) {
                for (int i = 0; i < n; i++)
                    ans[i] = comp[i % d];
                break;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
