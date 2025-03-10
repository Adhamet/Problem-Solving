#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 3005, oo = 1e9+7;
int n;
vector<int> fonts, cost;
int memo[MAXN][MAXN][4];

int recurse(int idx, int last, int taken) {
    if (taken == 3) return 0;
    if (idx > n) return oo;

    int &ret = memo[idx][last][taken];
    if (~ret) return ret;
    ret = oo;

    ret = recurse(idx + 1, last, taken);
    if (last == 0 || fonts[idx] > fonts[last]) 
        ret = min(ret, cost[idx] + recurse(idx + 1, idx, taken + 1));
    return ret;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> n;
    fonts.resize(n + 1), cost.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> fonts[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];

    int ans = recurse(1, 0, 0);
    return cout << (ans >= oo ? -1 : ans), 0;
}
