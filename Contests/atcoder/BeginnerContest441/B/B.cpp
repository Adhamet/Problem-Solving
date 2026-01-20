#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n,m;    std::cin >> n >> m;
    std::string s, t;   std::cin >> s >> t;

    int q;  std::cin >> q;
    while (q--) {
        std::string w;  std::cin >> w;
        std::set<char> st(w.begin(), w.end());
        
        int cnt1 = 0, cnt2 = 0;
        for (auto x: st) {
            if (s.find(x) != std::string::npos) cnt1++;
            if (t.find(x) != std::string::npos) cnt2++;
        }

        if (cnt1 == (int)st.size()) {
            if (cnt1 == cnt2) std::cout << "Unknown\n";
            else std::cout << "Takahashi\n";
        } else if (cnt2 == (int)st.size()) {
            std::cout << "Aoki\n";
        } else std::cout << "Unknown\n";
    }

    return 0;
}
