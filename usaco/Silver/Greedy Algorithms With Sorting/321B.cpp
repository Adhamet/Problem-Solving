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

    int n, m;
    cin >> n >> m;
    
    vector<int> atk, def, my;

    for (int i = 0; i < n; i++) {
        string x;
        int a;
        cin >> x >> a;
        if (x[0] == 'A') atk.push_back(a);
        else def.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        my.push_back(a);
    }

    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    sort(my.begin(), my.end());

    multiset<int> st, st2;
    ll res, ans = 0;

    for (int i = 0; i <= (int)atk.size(); i++) {
        st.clear();
        
		for (int j = 0; j < m; j++) st.insert(my[j]);

        if (i > (int)st.size()) break;

        res = 0;
        for (int j = i - 1; j >= 0; j--) {
            auto it = prev(st.end());
            if (atk[j] > *it) continue;
            res += *it - atk[j];
            st.erase(it);
        }
        ans = max(ans, res);
    }

    for (int j = 0; j < m; j++) st2.insert(my[j]);

    for (int i = 0; i < (int)def.size(); i++) {
        if (st2.empty() || *st2.rbegin() < def[i]) {
            cout << ans << el;
            return 0;
        }

        st2.erase(st2.upper_bound(def[i]));
    }

    res = 0;
    for (int i = (int)atk.size() - 1; i >= 0; i--) {
        if (st2.empty()) {
            cout << ans << el;
            return 0;
        }

        auto it = prev(st2.end());
        if (atk[i] > *it) {
            cout << ans << el;
            return 0;
        }

        res += *it - atk[i];
        st2.erase(it);
    }

    for (auto it = st2.begin(); it != st2.end(); it++) res += *it;
    cout << max(ans, res) << el;

    return 0;
}

