#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<i64> ev(n), od(n);
    ev[0] = a[0];
    if (n > 1) od[1] = a[1];
    for (int i = 1; i < n; i++) {
        ev[i] = ev[i-1], od[i] = od[i-1];
        if (!(i & 1)) ev[i] += a[i];
        else od[i] += a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        i64 evContrib = 0, odContrib = 0;
        if (i > 0) {
            if (i & 1) odContrib = od[i - 1], evContrib = ev[i];
            else evContrib = ev[i - 1], odContrib = od[i];
        }
        odContrib += ev[n - 1] - ev[i];
        evContrib += od[n - 1] - od[i];
        if (odContrib == evContrib) cnt += 1;
    }

    return std::cout << cnt, 0;
}
