#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        std::string s;  std::cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i]-'0';
        }

        std::string t = s;
        std::sort(t.begin(), t.end());
        if (s == t) {
            std::cout << "Bob\n";
            continue;
        } else {
            std::cout << "Alice\n";
            int zeros = std::count(s.begin(), s.end(), '0');
            std::vector<int> indices;

            for (int i = 0; i < zeros; i++) if (s[i] == '1') {
                indices.push_back(i+1);
            }

            for (int i = zeros; i < n; i++) if (s[i] == '0') {
                indices.push_back(i+1);
            }

            std::cout << (int)indices.size() << '\n';
            for (int x: indices) std::cout << x << ' ';
            std::cout << '\n';
        }
    
    }

    return 0;
}
