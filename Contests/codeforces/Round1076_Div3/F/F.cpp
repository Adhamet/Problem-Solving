#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;
        i64 ax, ay, bx, by;
        std::cin >> n >> ax >> ay >> bx >> by;

        std::vector<std::array<i64,2>> pts(n);
        for (int i = 0; i < n; i++) std::cin >> pts[i][0];
        for (int i = 0; i < n; i++) std::cin >> pts[i][1];

        std::sort(pts.begin(), pts.end());

        i64 curX = ax, curY = ay, tot = 0;
        for (int i = 0; i < n; ) {
            int j = i;

            i64 mn = pts[i][1], mx = pts[i][1];
            while (j < n && pts[j][0] == pts[i][0]) {
                mn = std::min(mn, pts[j][1]);
                mx = std::max(mx, pts[j][1]);
                ++j;
            }

            tot += (pts[i][0] - curX);
            curX = pts[i][0];

            if (curY < mn) {
                tot += (mx - curY);
                curY = mx;
            } else if (curY > mx) {
                tot += (curY - mn);
                curY = mn;
            } else {
                i64 opt1 = (mx - curY) + (mx - mn);
                i64 opt2 = (curY - mn) + (mx - mn);
                if (opt1 < opt2) {
                    tot += opt1;
                    curY = mn;
                } else {
                    tot += opt2;
                    curY = mx;
                }
            }

            i = j;
        }

        tot += (bx - curX) + std::llabs(curY - by);
        std::cout << tot << '\n';
    }

    return 0;
}

