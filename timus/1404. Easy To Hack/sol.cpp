#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string s;  std::cin >> s;
    int n = s.size();

    for (int i = n - 1; i > 0; i--) {
        s[i] = (s[i] - s[i-1] + 'a');
        s[i] += (s[i] < 'a' ? 26: 0);
    }

    s[0] -= 5;
    s[0] += (s[0] < 'a' ? 26: 0);

    std::cout << s;
}
