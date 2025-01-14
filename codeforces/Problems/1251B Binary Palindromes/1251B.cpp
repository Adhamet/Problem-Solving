#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;

        vector<string> bs(n);
        int oddsCnt = 0, bad = 0, zeros = 0, ones = 0;
        for (int i = 0; i < n; ++i) {
            cin >> bs[i];
            int m = bs[i].size();

            int cnt0 = 0, cnt1 = 0;
            for (char c : bs[i]) {
                if (c == '0') cnt0 += 1;
                else cnt1 += 1;
            }

            if (m % 2 != 0) oddsCnt += 1;
            else if (cnt0 % 2 != 0 || cnt1 % 2 != 0) bad += 1;
            zeros += cnt0, ones += cnt1;
        }

        if (oddsCnt > 0) cout << n << el;
        else {
            if (bad % 2 == 0) cout << n << el;
            else cout << n - 1 << el;
        }
    }

    return 0;
}

