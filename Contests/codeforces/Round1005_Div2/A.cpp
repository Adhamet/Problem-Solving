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
        int n;
        string s;
        cin >> n >> s;
        int transitions = 0;
        for (int i = 0; i < n - 1; ++i) if (s[i] == '1' && s[i+1] == '0') transitions++;

        int groups = 0;
        bool flag = false;
        for (char c : s) {
            if (c == '1' && !flag) {
                groups++;
                flag = true;
            } else if (c == '0') flag = false;
        }
        
        cout << transitions + groups << el;
    }

    return 0;
}