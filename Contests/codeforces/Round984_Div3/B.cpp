#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		i64 n, k;
		cin >> n >> k;

		map<i64, i64, greater<>> vals;
		for (int i = 0; i < k; i++) {
			i64 type, cost;
			cin >> type >> cost;
			vals[type] += cost;
		}

		vector<i64> t;
		for (auto itr = vals.begin(); itr != vals.end(); itr = next(itr)) {
			t.push_back(itr->second);
		}

		sort(t.begin(), t.end(), greater<>());
		i64 ans = 0;
		for (int i = 0; i < min(n, (i64)t.size()); i++) ans += t[i];
		cout << ans << el;
	}

	return 0;
}
