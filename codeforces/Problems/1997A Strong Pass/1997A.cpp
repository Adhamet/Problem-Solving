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
        string s;
        cin >> s;

        int idx = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) idx = i;
        }

        if (idx == -1) {
            cout << s;
            cout << char(((s.back() - 'a' + 1) % 26) + 'a') << el;
        } else {
            for (int i = 0; i < idx; i++) cout << s[i];
            cout << char(((s[idx] - 'a' + 1) % 26) + 'a');
            for (int i = idx; i < s.size(); i++) cout << s[i];
            cout << el;
        }
    }

    return 0;
}
