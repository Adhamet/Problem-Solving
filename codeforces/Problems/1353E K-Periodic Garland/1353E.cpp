#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, k;   std::cin >> n >> k;
        std::string s;  std::cin >> s;

        std::vector<int> prefOnes(n);   prefOnes[0] = (s[0]=='1');
        for (int i = 1; i < n; i++) prefOnes[i] = prefOnes[i-1] + (s[i]=='1');
        
        std::vector<int> seg[k];
        for (int i = 0; i < n; i++) {
            int v = i%k;
            seg[v].push_back(s[i] == '1'? 1: -1);
        }

        int ans = 0;
        for (int i = 0; i < k; i++) {
            int curV = 0, curA = 0;
            for (auto v: seg[i]) {
                curV = std::max(0, curV + v);
                curA = std::max(curA, curV);
            }
            ans = std::max(ans, curA);
        }

        std::cout << prefOnes[n-1] - ans << '\n';
    }

    return 0;
}
