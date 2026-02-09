#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        i64 m;
        std::cin >> n >> m;

        std::vector<i64> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::vector<i64> zeros;
        zeros.reserve(n);
        i64 totDigits = 0;
        for (i64 x: a) {
            i64 d = 0, y = x;
            while (y) {
                d++;
                y /= 10;
            }
            totDigits += d;

            i64 z = 0;
            while (x % 10 == 0) {
                z++;
                x /= 10;
            }
            zeros.push_back(z);
        }

        std::sort(zeros.rbegin(), zeros.rend());

        i64 annaZeros = 0;
        for (int i = 0; i < (int)zeros.size(); i += 2) {
            annaZeros += zeros[i];
        }

        std::cout << (totDigits - annaZeros >= m+1? "Sasha": "Anna") << '\n';
    }

    return 0;
}
