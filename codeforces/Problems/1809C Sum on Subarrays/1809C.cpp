#include <bits/stdc++.h>
using namespace std;
#define el '\n'

void solve(int32_t n, int32_t k, vector<int32_t>& ans) {
    if (k < n) {
        ans.assign(n, -1);
        if (k > 0) ans[k - 1] = 200;
        if (k < n) ans[k] = -400;
    } else {
        vector<int32_t> temp;
        solve(n - 1, k - n, temp);
        temp.push_back(1000);
        ans = temp;
    }
}

int32_t main() {
    int32_t tc;
    scanf("%d", &tc);

    while (tc--) {
        int32_t n, k;
        scanf("%d %d", &n, &k);
        vector<int32_t> ans;
        solve(n, k, ans);
        for (int x : ans) printf("%d ", x);
        printf("\n");
    }

    return 0;
}

