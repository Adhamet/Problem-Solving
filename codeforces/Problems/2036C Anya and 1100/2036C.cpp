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
		string s;
		cin >> s;

		int q;
		cin >> q;

		set<int> st;
		for (int i = 0; i <= (int)s.size() - 4; i++) {
			string tmp = s.substr(i, 4);
			if (tmp == "1100") st.insert(i);
		}

		while (q--) {
			int idx;
			char val;
			cin >> idx >> val;
			idx -= 1;

			for (int i = max(0, idx - 3); i <= min(idx, (int)s.size() - 4); i++) {
				string tmp = s.substr(i, 4);
				if (tmp == "1100") st.erase(i);
			}

			s[idx] = val;

			for (int i = max(0, idx - 3); i <= min(idx, (int)s.size() - 4); i++) {
				string tmp = s.substr(i, 4);
				if (tmp == "1100") st.insert(i);
			}

			cout << (st.size() > 0? "YES": "NO") << el;
		}
	}

	return 0;
}
