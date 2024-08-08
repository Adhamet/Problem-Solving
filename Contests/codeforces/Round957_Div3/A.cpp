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
        int a, b, c;
        cin >> a >> b >> c;

        int times = 5;

        while (times--) {
            if (a < b) {
                if (a < c) {
                    a += 1;
                } else {
                    c += 1;
                }
            } else {
                if (b < c) {
                    b += 1;
                } else {
                    c += 1;
                }
            }
        }

        cout << a * b * c << el;
    }

    return 0;
}
