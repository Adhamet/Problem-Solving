#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (t.length() >= 2 && s[i] == t.back() && s[i] == t[t.length()-2]) continue;
        if (t.length() >= 3 && s[i] == t.back()) {
            if (t[t.length()-2] == t[t.length()-3] && t.back() != t[t.length()-2]) {
            continue;
			}
        }

        t += s[i];
    }

	return cout << t, 0;
}
