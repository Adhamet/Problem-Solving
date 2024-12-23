#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    string pattern[] = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
    while (t--) {
        int n;
        string s, tmp;
        cin >> n >> s;

        int mn = INT_MAX;
        for (int i = 0; i < 7; i++) {
            int sz = pattern[i].size();
            for (int j = 0; j + sz <= n; j++) {
                tmp = s.substr(j, sz);
                if (tmp == pattern[i]) mn = min(mn, sz);
            }
        }

        cout << (mn == INT_MAX ? -1 : mn) << el;
    }

    return 0;
}

