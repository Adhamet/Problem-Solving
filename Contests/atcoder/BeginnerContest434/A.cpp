#include <bits/stdc++.h>

using i64 = long long;

int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);

      i64 w, b;   std::cin >> w >> b;
      std::cout << ((w * 1000) / b) + 1<< '\n';

      return 0;
}
