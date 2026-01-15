#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

bool onSegment(i64 x1, i64 y1, i64 x2, i64 y2, i64 x3, i64 y3) {
    if ((x2-x1) * (y3-y1) != (y2-y1) * (x3-x1)) return false;
    return std::min(x1, x2) <= x3 && x3 <= std::max(x1, x2) &&
           std::min(y1, y2) <= y3 && y3 <= std::max(y1, y2);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::unordered_set<u64> vis;
    auto markState = [&](int x, int y, const std::string& dir) {
        int dc = 0;
        if (dir == "UR") dc = 0;
        else if (dir == "UL") dc = 1;
        else if (dir == "DR") dc = 2;
        else if (dir == "DL") dc = 3;
        u64 msk = (u64(x) << 34) | (u32(y) << 16) | u32(dc);
        return vis.insert(msk).second;
    };

    int t;  std::cin >> t;
    while (t--) {
        vis.clear();
        int n, m;           std::cin >> n >> m;
        int sx, sy;         std::cin >> sx >> sy;
        int ex, ey;         std::cin >> ex >> ey;
        std::string dir;    std::cin >> dir;
        if (std::tie(sx, sy) == std::tie(ex, ey)) {
            std::cout << 0 << '\n';
            continue;
        }

        int move = 0;
        bool bounced = false;
        if ((dir[0] == 'U' && sx == 1) || (dir[0] == 'D' && sx == n)) {
            dir[0] = (dir[0] == 'U' ? 'D' : 'U');
            bounced = true;
        }
        if ((dir[1] == 'L' && sy == 1) || (dir[1] == 'R' && sy == m)) {
            dir[1] = (dir[1] == 'L' ? 'R' : 'L');
            bounced = true;
        }
        if (bounced) move++;

        markState(sx,sy,dir);

        int cx1 = sx, cy1 = sy, cx2 = 0, cy2 = 0;
        while (true) {
            if (dir == "DR") {
                int val;
                if (n-cx1 < m-cy1) val = n-cx1, dir = "UR";
                else if (n-cx1 > m-cy1) val = m-cy1, dir = "DL";
                else val = n-cx1, dir = "UL";
                cx2 = cx1 + val;
                cy2 = cy1 + val;
            } else if (dir == "DL") {
                int val;
                if (n-cx1 < cy1-1) val = n-cx1, dir = "UL";
                else if (n-cx1 > cy1-1) val = cy1-1, dir = "DR";
                else val = n-cx1, dir = "UR";
                cx2 = cx1 + val;
                cy2 = cy1 - val;
            } else if (dir == "UR") {
                int val;
                if (cx1-1 < m-cy1) val = cx1-1, dir = "DR";
                else if (cx1-1 > m-cy1) val = m-cy1, dir = "UL";
                else val = cx1-1, dir = "DL";
                cx2 = cx1 - val;
                cy2 = cy1 + val;
            } else { // dir == "UL"
                int val;
                if (cx1-1 < cy1-1) val = cx1-1, dir = "DL";
                else if (cx1-1 > cy1-1) val = cy1-1, dir = "UR";
                else val = cx1-1, dir = "DR";
                cx2 = cx1 - val;
                cy2 = cy1 - val;
            }

            if (onSegment(cx1,cy1,cx2,cy2,ex,ey)) {
                std::cout << move << '\n';
                break;
            } 

            move++;
            cx1 = cx2, cy1 = cy2;

            if (!markState(cx1,cy1,dir)) {
                std::cout << -1 << '\n';
                break;
            }
        }
    }

    return 0;
}
