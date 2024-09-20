#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int MAX_POS = 1e9;

int n;
vector<ll> a;

bool works_right(int start, ll rad) {
    int cur = start, next = 0;

    while (cur < a.back()) {
        while (next + 1 < n && a[next + 1] <= cur + rad) next++;
        if (a[next] == cur) return false;
        cur = a[next];
        rad -= 2;
    }

    return true;
}

bool works_left(int start, ll rad) {
    for (auto &x : a) x *= -1;
    reverse(a.begin(), a.end());
    bool res = works_right(-start, rad);
    reverse(a.begin(), a.end());
    for (auto &x : a) x *= -1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	setIO("angry");

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= 2;
    }

    sort(a.begin(), a.end());

    ll lo = 0, hi = 2 * MAX_POS;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        ll l = a.front(), r = a.back();
        while (l < r) {
            ll m = l + (r - l) / 2;
            if (works_right(m, mid)) r = m;
            else l = m + 1;
        }

        if (works_left(l, mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo / 2 << '.' << (lo % 2 ? 5 : 0) << el;

    return 0;
}
