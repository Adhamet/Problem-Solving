#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define fst first
#define scd second
#define ll long long

int n, m;
bool valid(ll x, ll y) { return x > 0 && x <= n && y > 0 && y <= m; }
int main() {
    ios_base::sync_with_stdio(0), std::cin.tie(nullptr);

    ll x, y, k, ans = 0;
    pair<ll, ll> currVec;
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < k; i++) {
        cin >> currVec.fst >> currVec.scd;
        ll l = 0, r = 1e9 + 9, steps = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (valid(x + (currVec.fst * mid), y + (currVec.scd * mid))) {
                steps = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        ans += steps;
        x = (currVec.fst * steps) + x;
        y = (currVec.scd * steps) + y;
    }

    cout << ans << el;
    return 0;
}
