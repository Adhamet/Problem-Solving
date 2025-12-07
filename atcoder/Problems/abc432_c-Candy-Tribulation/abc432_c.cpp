#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

      i64 n, X, Y;
      cin >> n >> X >> Y;
      int a[n];
      for (int i = 0; i < n; ++i) std::cin >> a[i];

      i64 C = Y - X;

      i64 rhs = (a[0] * X) % C;
      for (int i = 1; i < n; i++) if ((a[i] * X) % C != rhs) {
            cout << -1 << el;
            return 0;
      }

      i64 l = LLONG_MIN, r = LLONG_MAX;
      for (int i = 0; i < n; i++) {
            l = max(l, a[i] * X);
            r = min(r, a[i] * Y);
      }

      if(l > r) return cout << -1, 0;

      i64 w = r;
      long double tot = 0;
      for (int i = 0; i < n; i++) tot += (w - X * a[i]) / (long double)C;

      return std::cout << (i64)(tot + 0.5L), 0;
}

