#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    map<string, int> mp;
    int i = 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        for (char d = 'a'; d <= 'z'; ++d) {
            if (c != d) mp[string(1, c) + d] = i++;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << mp[s] << el;
    }

    return 0;
}