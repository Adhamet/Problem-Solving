#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];

        sort(a.begin(), a.end());

        int score1 = 0;
        if (k > 0) {
            for (int i = 0; i < n - 2*k; ++i) score1 += a[i];
            for (int i = 0; i < k; ++i) score1 += a[n - 2*k + i] / a[n - 2*k + i + k];
        }

        vector<int> tmp_a = a;
        int score2 = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> tmp = tmp_a;
            int m = tmp.size();
            for (int j = 0; j < m - 1; ++j) tmp[j] = tmp[j] / tmp[m - 1];

            int mxChange = 0, mxJ = 0;
            for (int j = 0; j < m - 1; ++j) {
                int change = tmp_a[j] - tmp[j];
                if (change > mxChange) mxChange = change, mxJ = j;
            }

            score2 += tmp[mxJ];
            tmp_a.pop_back();
            tmp_a.erase(tmp_a.begin() + mxJ);
        }

        for (int num: tmp_a) score2 += num;

        if (k == 0) cout << sum << el;
        else cout << min(score1, score2) << el;
    }

    return 0;
}