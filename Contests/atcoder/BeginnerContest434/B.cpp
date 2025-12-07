#include <bits/stdc++.h>

using i64 = long long;

int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout << std::fixed << std::setprecision(11);

      i64 n, m;   std::cin >> n >> m;
      std::vector<long double> prefWei(m), cnt(m);
      for (int i = 0; i < n; ++i) {
            int a;
            long double b;
            std::cin >> a >> b;
            prefWei[a-1] += b;
            cnt[a-1] += 1;
      }

      for (int i = 0; i < m; ++i) std::cout << prefWei[i] / cnt[i] << '\n';

      return 0;
}
