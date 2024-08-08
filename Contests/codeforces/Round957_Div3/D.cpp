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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        string input;
        cin >> input;

        string river = "B";
        river += input;
        river.push_back('B');

        int i = 0;

        while (true) {
            int dist = min(i + m, (int)river.size() - 1);

            if (dist == river.size() - 1) {
                cout << "YES\n";
                break;
            }

            int waterIdx = 0;

            bool platformFound = false, waterFound = false;

            while (dist > i) {
                if (river[dist] == 'B' || river[dist] == 'L') {
                    platformFound = true;
                    break;
                } else if (!waterFound && river[dist] == 'W') {
                    waterFound = true;
                    waterIdx = dist;
                }

                dist -= 1;
            }


            if (platformFound) {
                i = dist;
            } else if (waterFound) {
                while (k && river[waterIdx] == 'W') {
                    waterIdx += 1;
                    k -= 1;
                }

                if (river[waterIdx] == 'C' || (k == 0 && river[waterIdx] == 'W')) {
                    cout << "NO\n";
                    break;
                }

                i = waterIdx;
            } else {
                cout << "NO\n";
                break;
            }
        }
    }

    return 0;
}
