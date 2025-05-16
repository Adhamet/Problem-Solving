#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, o = 0, no = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) o += 1;
            else if (a[i] == -1) no += 1;
        }

        if ((o + no) % 2 != 0) {
            cout << -1 << el;
            continue;
        }

        if (o == no) {
            cout << n << el;
            for (int i = 0; i < n; ++i)
                cout << i + 1 << ' ' << i + 1 << el;
        } else if (o > no) {
            int excess = o - no;
            int req = excess / 2;
            vector<pair<int, int>> ans;

            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if ((a[i] == 0 && a[i+1] == 1) || (a[i] == 1 && a[i+1] == 1))
                    cnt++;
            }

            if (req > cnt) {
                cout << -1 << el;
                continue;
            }

            int i = 0;
            while (i < n) {
                if (a[i] == -1) {
                    ans.emplace_back(i+1, i+1);
                    i++;
                } else if (i < n-1 && req > 0 && ((a[i] == 0 && a[i+1] == 1) || (a[i] == 1 && a[i+1] == 1))) {
                    ans.emplace_back(i+1, i+2);
                    req--;
                    i += 2;
                } else {
                    ans.emplace_back(i+1, i+1);
                    i++;
                }
            }

            cout << ans.size() << el;
            for (auto &pr : ans) cout << pr.first << ' ' << pr.second << el;
        } else {
            int excess = no - o;
            int req = excess / 2;
            vector<pair<int, int>> ans;

            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if ((a[i] == 0 && a[i+1] == -1) || (a[i] == -1 && a[i+1] == -1))
                    cnt++;
            }

            if (req > cnt) {
                cout << -1 << el;
                continue;
            }

            int i = 0;
            while (i < n) {
                if (a[i] == 1) {
                    ans.emplace_back(i+1, i+1);
                    i++;
                } else if (i < n-1 && req > 0 && ((a[i] == 0 && a[i+1] == -1) || (a[i] == -1 && a[i+1] == -1))) {
                    ans.emplace_back(i+1, i+2);
                    req--;
                    i += 2;
                } else {
                    ans.emplace_back(i+1, i+1);
                    i++;
                }
            }

            cout << ans.size() << el;
            for (auto &pr : ans) cout << pr.first << ' ' << pr.second << el;
        }
    }

    return 0;
}
