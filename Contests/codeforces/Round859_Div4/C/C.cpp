#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::string s; std::cin >> s;

        std::set<char> st;
        for (int i = 0; i < n; i+=2) {
            st.insert(s[i]);
        }

        bool acc = true;
        for (int i = 1; i < n; i+=2) {
            if (st.find(s[i]) != st.end()) {
                acc = false;
                break;
            }
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
