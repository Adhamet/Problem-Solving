#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool acc = true;
        vector<char> grp(k, '?');

        for (int g = 0; g < k; ++g) {
            bool has0 = false, has1 = false;
            for (int i = g; i < n; i += k) {
                if (s[i] == '0') has0 = true;
                else if (s[i] == '1') has1 = true;
            }

            if (has0 && has1) {
                acc = false;
                break;
            } else if (has0) grp[g] = '0';
            else if (has1) grp[g] = '1';
            else grp[g] = '?';
        }

        if (!acc) {
            cout << "NO" << el;
            continue;
        }

        int fixed0 = 0, fixed1 = 0;
        for (int g = 0; g < k; ++g) {
            if (grp[g] == '0') fixed0++;
            else if (grp[g] == '1') fixed1++;
        }

        int free = k - fixed0 - fixed1;
        int req0 = (k / 2) - fixed0;
        int req1 = (k / 2) - fixed1;

        if (req0 >= 0 && req1 >= 0 && (req0 + req1 == free)) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}
