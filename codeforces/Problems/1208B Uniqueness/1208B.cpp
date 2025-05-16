#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	set<int> st;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		st.insert(a[i]);
	}

	unordered_map<int,int> compressedVal;
	int id = 0;
	for (auto& x: st) compressedVal[x] = id++;

	st.clear();
	vector<int> freq(id, 0);
	for (int i = 0, cval; i < n; ++i) {
		cval = compressedVal[a[i]];
		freq[cval] += 1;
		if (freq[cval] > 1) st.insert(cval);
	}

	for (auto& x: st) {
		int cval = compressedVal[x];
		if (freq[x] > 1) freq[x] -= 1;
	}

	if (st.empty()) return cout << 0, 0;

	int ans = INT_MAX;
	for (int i = 0, cval; i < n; ++i) {
		vector<int> cfreq = freq;
		set<int> cst = st;
		for (int j = i; j < n; ++j) {
			cval = compressedVal[a[j]];
			if (cst.count(cval)) {
				cfreq[cval] -= 1;
				if (cfreq[cval] == 0)
					cst.erase(cval);
			}

			if (cst.empty()) {
				ans = min(ans, j-i+1);
				break;
			}
		}
	}

	return cout << ans, 0;
}
