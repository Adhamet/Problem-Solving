#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &i: a) cin >> i;
        for (auto &i: b) cin >> i;

		bool sorted = true;
        vector<pi> moves;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (a[j] > a[j + 1] || b[j] > b[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                    moves.push_back({j + 1, j + 2});
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1] || b[i] > b[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (!sorted) {
            cout << -1 << el;
        } else {
            cout << moves.size() << el;
            for (auto &move : moves) {
                cout << move.F << " " << move.S << el;
            }
        }
    }

    return 0;
}
