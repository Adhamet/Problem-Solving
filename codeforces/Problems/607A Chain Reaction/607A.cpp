#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 1e5+10, oo = 1e9+7;
int32_t n;
int64_t memo[MAXN];
array<int64_t, 2> beacon[MAXN];

int64_t recurse(int32_t idx) {
    if (idx == -1) return 0;

    int64_t &ret = memo[idx];
    if (~ret) return ret;
    ret = oo;

    int32_t l = 0, r = idx, destroy = -1;
    while (l <= r) {
        int32_t mid = (l + r) >> 1;
        if (beacon[mid][0] >= beacon[idx][0] - beacon[idx][1]) r = mid - 1, destroy = mid;
        else l = mid + 1;
    }

    if (~destroy) // take
        ret = min(ret, (idx - destroy) + recurse(destroy - 1));
    return ret = min(ret, (n - idx) + recurse(idx - 1)); // leave
}

int32_t main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%ld %ld", &beacon[i][0], &beacon[i][1]);
	sort(beacon, beacon + n);
    memset(memo, -1, sizeof(memo));
    return printf("%ld", recurse(n - 1)), 0;
}

