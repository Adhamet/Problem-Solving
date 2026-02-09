#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int p;  std::cin >> p;

        bool acc = false;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if ((i + 1) + (j + 1) + (k + 1) == p) {
                        acc = true;
                        std::string s = "";
                        s += (i + 'a');
                        s += (j + 'a');
                        s += (k + 'a');
                        std::cout << s << '\n';
                        break;
                    }
                    if (acc) break;
                }
                if (acc) break;
            }
            if (acc) break;
        }
    }

    return 0;
}
