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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<pair<int, int>> gaps;
        int firstW = -1, lastW = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (firstW == -1) firstW = i;
                lastW = i;
            } else if (i > 0 && s[i - 1] == 'W') {
                int j = i;
                while (j < n && s[j] == 'L') j++;
                if (j < n && s[j] == 'W') gaps.push_back({j - i, i});
                i = j - 1;
            }
        }

        sort(gaps.begin(), gaps.end());
        for (auto [size, start] : gaps) {
            if (k >= size) {
                for (int i = start; i < start + size; ++i) s[i] = 'W';
                k -= size;
            } else {
                for (int i = start; i < start + k; ++i) s[i] = 'W';
                k = 0;
                break;
            }
        }

        for (int i = firstW - 1; i >= 0 && k > 0; --i) {
            if (s[i] == 'L') {
                s[i] = 'W';
                k--;
            }
        }

        for (int i = lastW + 1; i < n && k > 0; ++i) {
            if (s[i] == 'L') {
                s[i] = 'W';
                k--;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                cnt += 1;
                if (i > 0 && s[i - 1] == 'W') cnt += 1;
            }
        }

        cout << cnt << el;
    }

    return 0;
}
