#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<char> s(n), t(n);

        for (auto &i: s) cin >> i;
        for (auto &i: t) cin >> i;

        bool acc = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') {
                acc = false;
                break;
            } else if (s[i] == '0' && t[i] == '0') continue;
            else break;
        }

        if (acc) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
