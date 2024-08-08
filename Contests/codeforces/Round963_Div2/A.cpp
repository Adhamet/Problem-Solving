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

        int sz = (int)s.size();
        int a=0,b=0,c=0,d=0;
        for (int i = 0; i < sz; i++) {
            if (s[i]=='A') a++;
            else if (s[i] == 'B') b++;
            else if (s[i] == 'C') c++;
            else if (s[i] == 'D') d++;
        }

        int ans = 0;
        if (a >= n) ans += n;
        else ans += a;
        if (b >= n) ans += n;
        else ans += b;
        if (c >= n) ans += n;
        else ans += c;
        if (d >= n) ans += n;
        else ans += d;

        cout << ans << el;
    }

    return 0;
}
