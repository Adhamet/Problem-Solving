#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, i64>> items(n);
    i64 tot_p = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].first >> items[i].second;
        tot_p += items[i].second;
    }

    std::sort(items.begin(), items.end(), [](auto &a, auto &b){
        return a.first + a.second < b.first + b.second;
    });

    i64 accu = 0, ans = n-1;
    for (int i = 0; i < n; i++) {
        accu += items[i].first + items[i].second;
        if (accu > tot_p) {
            ans = i;
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;  std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
