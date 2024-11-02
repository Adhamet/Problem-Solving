#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int step, mod;
	while (cin >> step >> mod) {
		int pt = 0;
		set<int> st;
		st.insert(pt);
		for (int i = 1; i <= mod - 1; i++) {
			pt = (pt + step) % mod;
			st.insert(pt);
		}

		cout << setw(10) << step << setw(10) << mod << "    ";
		cout << (st.size() == mod? "Good Choice\n": "Bad Choice\n") << el;
	}

	return 0;
}
