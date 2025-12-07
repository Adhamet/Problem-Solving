#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      i64 n, k = 0;      std::cin >> n;
      std::vector<int> b(n);
      for (int i = 0; i < n; ++i) std::cin >> b[i], k += (b[i] > 0);
      i64 tot = std::accumulate(b.begin(), b.end(), 0LL);
      std::cout << std::min(n, std::min(k, tot-(n-1))) << '\n';
}

int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      
      int t;      std::cin >> t;
      while (t--) {
            solve();
      }
      
      return 0;
}
