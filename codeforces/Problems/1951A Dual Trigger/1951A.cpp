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

        string s;
        cin >> s;

        int cnt = 0;
        bool deny = false;

        for (int i = 0; i < n; i++) {
            cnt += (s[i] - '0');

            if (i > 0 && s[i] == '1' && s[i - 1] == '1') deny = true;
        }

        if (cnt % 2 == 0) {
            if (cnt == 2 && deny) cout << "NO\n";
            else cout << "YES\n";
        } else cout << "NO\n";
    }

    return 0;
}
