#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<std::pair<int,int>> a(n);
        std::map<int,int> freq;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i].first, a[i].second = i;
            freq[a[i].first]++;
        }
        std::sort(a.begin(), a.end());
        bool acc = false;
        for (int i = 0; i < n; i++) {
            if (freq[a[i].first] == 1) {
                acc = true;
                std::cout << a[i].second + 1 << '\n';
                break;
            }
        }
        if (!acc) std::cout << -1 << '\n';
    }

    return 0;
}
