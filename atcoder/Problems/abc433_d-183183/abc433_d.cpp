#include <bits/stdc++.h>

using i64 = long long;

int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);

      int n;
      i64 m;      std::cin >> n >> m;

      std::vector<i64> a(n);
      for (int i = 0; i < n; ++i) std::cin >> a[i];

      i64 tens[11]; tens[0] = 1 % m;
      for (int i = 1; i <= 10; ++i) tens[i] = (tens[i-1] * 10) % m;

      std::vector<std::unordered_map<i64,int>> cnt(11);
      for (int i = 0; i < n; ++i) {
            cnt[(int)std::to_string(a[i]).size()][a[i] % m]++;
      }

      i64 ans = 0;
      for (int i = 0; i < n; ++i) {
            for (int d = 1; d <= 10; ++d) {
                  auto it = cnt[d].find((m - ((a[i]%m) * tens[d] % m)) % m);
                  if(it != cnt[d].end()) ans += it->second;
            }
      }

      return std::cout << ans, 0;
}

