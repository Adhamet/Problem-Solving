#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)3e5+5;

int a[MXN], mem[MXN][7], n;
std::vector<std::vector<int>> dices = {
    {2,3,4,5},
    {1,3,4,6},
    {1,2,5,6},
    {1,2,5,6},
    {1,3,4,6},
    {2,3,4,5}
};

int go(int idx, int lst) {
    if (idx == n) return 0;

    int &ret = mem[idx][lst];
    if (~ret) return ret;
    ret = INT_MAX;

    for (int cur = 1; cur <= 6; cur++) {
        bool pass = false;
        if (lst == 0) pass = true;
        else {
            for (int v: dices[lst-1]) {
                if (v == cur) {
                    pass = true;
                    break;
                }
            }
        }

        if (pass) {
            if (cur == a[idx])
                ret = std::min(ret, go(idx + 1, cur));
            else ret = std::min(ret, 1 + go(idx + 1, cur));
        }
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 7; j++)
                mem[i][j] = -1;
        std::cout << go(0, 0) << '\n';
    }

    return 0;
}
