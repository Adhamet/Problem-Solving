#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)2e5+5;

int n;
bool a[MXN];
int mem[MXN][2];    // idx, turn {0: f, 1: me}

int go(int idx, int turn) {
    if (idx == n) return 0;

    int &ret = mem[idx][turn];
    if (~ret) return ret;
    ret = (int)INT_MAX;

    if (turn == 0) { // [0, kill],[1, skip | skip&kill]
        if (a[idx] == 0) {
            ret = std::min(ret, go(idx + 1, !turn));
            if (idx + 1 < n && a[idx + 1] == 0)
                ret = std::min(ret, go(idx + 2, !turn));
            else ret = std::min(ret, go(idx + 2, !turn) + 1);
        } else {
            ret = std::min(ret, go(idx + 1, !turn) + 1);
            if (idx + 1 < n && a[idx + 1] == 0)
                ret = std::min(ret, go(idx + 2, !turn) + 1);
            else ret = std::min(ret, go(idx + 2, !turn) + 2);
        }
    } else { // [kill 1 | kill two]
        ret = std::min({ret, go(idx+1, !turn), go(idx+2, !turn)});
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) mem[i][0] = mem[i][1] = -1;
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            a[i] = (bool)x;
        }

        std::cout << go(0, 0) << '\n'; 
    }

    return 0;
}

