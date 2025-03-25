#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
    int32_t n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);

    vector<int32_t> hp(n);
    for (int i = 0; i < n; ++i) scanf("%d", &hp[i]);

    int32_t ans = 0;
    vector<int32_t> skips;
    for (int i = 0; i < n; ++i) {
        int32_t gameRounds = (hp[i] - 1) / (a + b);
        int32_t rem = hp[i] - gameRounds * (a + b);

        if (rem == 0) rem = a + b; 

        if (rem <= a) {
            ans++;
            continue;
        }

        rem -= a;

        int32_t req = (rem + a - 1) / a;
        skips.push_back(req);
    }

    sort(skips.begin(), skips.end());
    for (int32_t s : skips) {
        if (k >= s) k -= s, ans++;
        else break;
    }

    return printf("%d", ans);
}

