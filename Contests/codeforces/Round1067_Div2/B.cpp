#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      int n;      std::cin >> n;
      int a[2*n];
      std::map<int, int> freq;
      for (int i = 0; i < 2*n; ++i) std::cin >> a[i], freq[a[i]]++;

      i64 ans = 0;
      for (auto [x, f]: freq) {
            int cei = (f + 2 - 1) / 2;
            int flo = f / 2;
            if (cei & 1) ans += 1;
            if (flo & 1) ans += 1;
      }
      
      std::cout << ans << '\n';
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
