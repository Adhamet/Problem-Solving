#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int maxEle = 0, maxIdx = 0;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (i != 0) {
                if (p[i] > maxEle) {
                    maxEle = p[i];
                    maxIdx = i;
                }
            }
        }

        if (n == 1) {
            cout << p[0] << el;
            continue;
        }


        int ansL, ansR;

        if (maxIdx == n - 1) {
            if (p[n - 2] > p[0]) {
                ansL = n - 2;
                while (ansL > 0 && p[ansL - 1] > p[ansL]) ansL--;
            } else ansL = n - 1;
            ansR = n - 1;
        } else {
            ansL = maxIdx - 1;
            ansR = maxIdx - 1;
            if (p[ansL - 1] < p[0]) ansL = maxIdx - 1;
            else {
                while (ansL > 0 && p[ansL - 1] > p[0]) ansL -= 1;
            }
        }


        vector<int> res;
        for (int i = ansR + 1; i < n; i++) res.push_back(p[i]);
        for (int i = ansR; i >= ansL; i--) res.push_back(p[i]);
        for (int i = 0; i < ansL; i++) res.push_back(p[i]);

        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << el;
    }

    return 0;
}
