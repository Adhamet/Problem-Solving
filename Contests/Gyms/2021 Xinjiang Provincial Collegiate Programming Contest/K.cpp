#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
    string s; cin >> s;
    int p1, p2, l; cin >> p1 >> p2 >> l;

    string res1 = s, res2 = s;
    for (int i = 0; i < l; i++)
        res1[p2 - 1 + i] = res1[p1 - 1 + i];
    for (int i = 0; i < l; i++)
        res2[p2 - 1 + i] = s[p1 - 1 + i];

    return cout << res1 << el << res2 << el, 0;
}
