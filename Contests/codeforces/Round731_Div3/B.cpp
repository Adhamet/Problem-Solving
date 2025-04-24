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
        string s;
        cin >> s;
        int n = (int)s.size();

        bool acc = true;
        char i = 'a' + n - 1;

        int l = 0, r = n - 1;
        while (i >= 'a') {
            if (i == s[l]) l += 1;
            else if (i == s[r]) r -= 1;
            else {
                acc = false;
                break;
            }

            i -= 1;
        }

        cout << (acc ? "YES" : "NO") << el;
    }

    return 0;
}