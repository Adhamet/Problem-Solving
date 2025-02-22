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
        int n, num = 1;
        cin >> n;

        vector<int> a(n, 0), b(n - 1, 0);
        for (int i = 1; i <= n - 2; i++) {
            cin >> b[i];
        }

        for (int i = 1; i <= n - 2; i++) {
            if (b[i] == 1) {
                a[i - 1] = num;
                a[i] = num;
                a[i + 1] = num;
            } else if (a[i] == 0) {
                a[i] = ++num;
            }
        }

        bool acc = true;
        for (int i = 1; i <= n - 2; i++) {
            if (b[i] == 1) {
                if (a[i] != a[i - 1] || a[i] != a[i + 1]) {
                    acc = false;
                    break;
                }
            } else {
                if (a[i] == a[i - 1] && a[i] == a[i + 1]) {
                    acc = false;
                    break;
                }
            }
        }

        cout << (acc ? "YES" : "NO") << el;
    }

    return 0;
}