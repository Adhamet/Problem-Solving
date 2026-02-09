#include <bits/stdc++.h>

using i64 = long long;

const int MOD = (int)1e9+7;

int n, x;
i64 memo[120][120][120];
std::vector<int> a;

i64 addm(int x, int y) { x += y; return (x >= MOD)? x - MOD: x; }

i64 go(int i, int mn, int mx) {
    if (i >= n) return 1;

    i64 &ret = memo[i][mn][mx];
    if (~ret) return ret;
    ret = 0;

    ret = addm(ret, go(i + 1, mn, mx));   // skip;
    if (mn == 105) ret = addm(ret, go(i + 1, a[i], a[i]));
    else {
        if (a[i] <= mn && mx - a[i] <= x)
            ret = addm(ret, go(i + 1, a[i], mx));
        if (a[i] >= mx && a[i] - mn <= x)
            ret = addm(ret, go(i + 1, mn, a[i]));
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    a.reserve(150);
    for (int i = 0; i < 108; i++)
        for (int j = 0; j < 108; j++)
            for (int k = 0; k < 108; k++)
                memo[i][j][k] = -1;

    std::cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int tmp;    std::cin >> tmp;
        a.push_back(tmp);
    }
    std::sort(a.begin(), a.end());
    
    return std::cout << go(0, 105, 105), 0;
}
