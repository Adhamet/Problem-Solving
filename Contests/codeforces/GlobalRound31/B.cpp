#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;

    std::string s = "";
    for (int i = 0; i < n; i++) {
        std::string x;
        std::cin >> x;
        int m = (int)x.size();
        
        std::string ss1 = s, ss2 = s;
        ss1 = x + ss1;
        ss2 = ss2 + x;
        if (ss1 <= ss2) {
            s = x + s;
        } else s += x;
    }

    std::cout << s << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
