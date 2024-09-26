#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> lf(n), rt(n);

        lf[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) lf[i] = lf[i - 1];
            if (s[i] == '0') lf[i] = i;
        }

        rt[n - 1] = n;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 1 < n) rt[i] = rt[i + 1];
            if (s[i] == '1') rt[i] = i;
        }

        set<pi> st;
        for (int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int firstOne = rt[l], lastZero = lf[r];
            if (firstOne > lastZero) st.insert(make_pair(-1, -1));
            else st.insert(make_pair(firstOne, lastZero));
        }

        cout << st.size() << el;
    }

    return 0;
}
