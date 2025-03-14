#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int SZ = 1003;
int32_t grid[SZ][SZ], dp1[SZ][SZ], dp2[SZ][SZ], dp3[SZ][SZ], dp4[SZ][SZ];

int32_t main() {
    int32_t n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &grid[i][j]);

    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));
    memset(dp4, 0, sizeof(dp4));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = grid[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp2[i][j] = grid[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = grid[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = grid[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

    int32_t ans = 0;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            int32_t op1 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
            int32_t op2 = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
            ans = max(ans, max(op1, op2));
        }
    }

    return printf("%d", ans), 0;
}
