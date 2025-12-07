#include <bits/stdc++.h>

using i64 = long long;

void solve() {
      i64 n, k;   std::cin >> n >> k;
      i64 a[n], b[n];
      for (int i = 0; i < n; ++i) std::cin >> a[i];
      for (int i = 0; i < n; ++i) std::cin >> b[i];

      i64 ans1 = a[0] + b[0], cur1 = a[0], mxSoFar = b[0];
      i64 ans2 = a[0], cur2 = a[0];
      for (int i = 1; i < n; ++i) {
            mxSoFar = std::max(mxSoFar, b[i]);
            if (a[i] + b[i] > cur1 + a[i] + mxSoFar) {
                  cur1 = a[i], mxSoFar = b[i];
            } else cur1 = cur1 + a[i];
            cur2 = std::max(a[i], cur2 + a[i]);

            ans2 = std::max(ans2, cur2);
            ans1 = std::max(ans1, cur1 + mxSoFar);
      }

      std::cout << (k&1? ans1: ans2) << '\n';
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

