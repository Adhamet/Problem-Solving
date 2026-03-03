#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct areaCovered {
    int x1, y1;
    int x2, y2;
};

struct Robot {
    int idx;
    int x, y, f[4];
    areaCovered ac;
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // lets work on the worst one, the one with least capabilities
    // lets say its 0 0 0 0, then its a point, so we work with that point and see
    // if other robots can reach it, so we're basing our solution based on the
    // most incapable of moving robot.
    //
    // ranking incapabilities
    // [1] 0 0 0 0
    // [2] 0 0 0 1, 0 0 1 0, 0 1 0 0, 1 0 0 0 (just 1 one)
    // [3] 0 0 1 1, (two ones)
    // [4] 0 1 1 1, (three ones)
    // [5] 1 1 1 1

    int q;  std::cin >> q;
    while (q--) {
        int n;  std::cin >> n;

        int leastOnes = 4;
        Robot worstR;
        std::vector<Robot> r(n);
        for (int i = 0; i < n; i++) {
            r[i].idx = i;
            std::cin >> r[i].x >> r[i].y;
            r[i].ac.x1 = r[i].ac.x2 = r[i].x;
            r[i].ac.y1 = r[i].ac.y2 = r[i].y;

            int ones = 0;
            std::cin >> r[i].f[0] >> r[i].f[1] >> r[i].f[2] >> r[i].f[3];
            if (r[i].f[0] == 1) ones++;
            if (r[i].f[1] == 1) ones++;
            if (r[i].f[2] == 1) ones++;
            if (r[i].f[3] == 1) ones++;
            
            if (ones <= leastOnes) {
                leastOnes = ones;
                worstR = r[i];
            }
        }

        auto computeAreaCovered = [](Robot& cr) {
            if (cr.f[0] == 1) cr.ac.x1 = (int)-1e5;
            if (cr.f[3] == 1) cr.ac.y1 = (int)-1e5;
            if (cr.f[2] == 1) cr.ac.x2 = (int)+1e5;
            if (cr.f[1] == 1) cr.ac.y2 = (int)+1e5;
        };

        auto areIntersecting = [](Robot rb1, Robot rb2, Robot &inter) -> bool {
            inter.ac.x1 = std::max(rb1.ac.x1, rb2.ac.x1);
            inter.ac.y1 = std::max(rb1.ac.y1, rb2.ac.y1);
            inter.ac.x2 = std::min(rb1.ac.x2, rb2.ac.x2);
            inter.ac.y2 = std::min(rb1.ac.y2, rb2.ac.y2);
            if (inter.ac.x1 > inter.ac.x2) return false;
            if (inter.ac.y1 > inter.ac.y2) return false;
            return true;
        };

        bool acc = true;
        computeAreaCovered(worstR);
        Robot intersection = worstR;
        for (int i = 0; i < n; i++) {
            if (i == worstR.idx) continue;
            computeAreaCovered(r[i]);
            
            if (!areIntersecting(intersection, r[i], intersection)) {
                acc = false;
                break;
            }
        }

        if (!acc) std::cout << 0 << '\n';
        else std::cout << 1 << ' ' << intersection.ac.x1 << ' ' << intersection.ac.y1 << '\n';
    }


    return 0;
}
