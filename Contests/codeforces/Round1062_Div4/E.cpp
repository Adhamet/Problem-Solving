#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool can(i64 d, vector<i64>& a, i64 x, int k) {
    i64 covered = 0;
    i64 L = max(0LL, a[0] - (d - 1));
    i64 R = min(x, a[0] + (d - 1));
    for (int i = 1; i < (int)a.size(); ++i) {
        i64 l = max(0LL, a[i] - (d - 1));
        i64 r = min(x, a[i] + (d - 1));
        if (l <= R + 1) R = max(R, r);
        else {
            covered += R - L + 1;
            L = l; R = r;
        }
    }
    covered += R - L + 1;
    return (x + 1 - covered) >= k;
}

void solve() {
    int n, k; i64 x;
    cin >> n >> k >> x;
    vector<i64> a(n);
    for (auto& v : a) cin >> v;
    sort(a.begin(), a.end());

    i64 low = 0, high = x + 1;
    while (low <= high) {
        i64 mid = (low + high) / 2;
        if (mid == 0) low = mid + 1;
        else if (can(mid, a, x, k)) low = mid + 1;
        else high = mid - 1;
    }
    i64 d = high;

    vector<pair<i64,i64>> blocks;
    i64 L = max(0LL, a[0] - (d - 1));
    i64 R = min(x, a[0] + (d - 1));
    for (int i = 1; i < n; ++i) {
        i64 l = max(0LL, a[i] - (d - 1));
        i64 r = min(x, a[i] + (d - 1));
        if (l <= R + 1) R = max(R, r);
        else { blocks.push_back({L,R}); L = l; R = r; }
    }
    blocks.push_back({L,R});

    vector<i64> res;
    i64 prev = -1;
    for (auto [l,r] : blocks) {
        for (i64 i = prev + 1; i < l && (int)res.size() < k; ++i)
            res.push_back(i);
        prev = r;
        if ((int)res.size() >= k) break;
    }
    for (i64 i = prev + 1; i <= x && (int)res.size() < k; ++i)
        res.push_back(i);

    for (auto v : res) cout << v << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

