#include <bits/stdc++.h>
using namespace std;
 
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'
 
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pll> intervals(m);
    for (auto &itv: intervals) cin >> itv.first >> itv.second;
    sort(intervals.begin(), intervals.end());

    auto can = [&](ll D) -> bool {
        int rem = n - 1;
        ll currPos = intervals[0].first;

        for (int i = 0; i < m; ++i) {
            ll start = max(currPos + D, intervals[i].first);
            while (start <= intervals[i].second && rem > 0) currPos = start, start += D, rem--;
        }

        return rem == 0;
    };

    ll l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (can(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << el;

    return 0;
}

