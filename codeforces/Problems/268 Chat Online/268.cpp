#include <bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define el '\n'
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), std::cin.tie(nullptr);

    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<pair<int, int>> x(p), z(q);
    for (int i = 0; i < p; i++) cin >> x[i].fst >> x[i].scd;
    for (int i = 0; i < q; i++) cin >> z[i].fst >> z[i].scd;

    int ans = 0;
    for (int t = l; t <= r; t++) {
        bool found = false;
        for (int i = 0; i < p && !found; i++) {
            for (int j = 0; j < q && !found; j++) {
                int sfst = z[j].fst + t;
                int sscd = z[j].scd + t;
                if (sfst <= x[i].scd && x[i].fst <= sscd) {
                    ans++;
                    found = true;
                }
            }
        }
    }

    cout << ans << el;
    return 0;
}
