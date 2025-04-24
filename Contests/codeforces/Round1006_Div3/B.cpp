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
        cin >> n;
        string s;
        cin >> s;

        int eyes = 0, mouth = 0;
        for (char c: s) {
            if (c == '-') eyes++;
            else mouth++;
        }

        if (eyes < 2 || mouth < 1) cout << 0 << el;
        else {
            int a = eyes / 2;
            int b = eyes - a;
            cout << mouth * a * b << el;
        }
    }

    return 0;
}