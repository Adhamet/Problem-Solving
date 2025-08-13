#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 1e5+5;

	int n;	cin >> n;
	vector<int> a(n), freq(MXN);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		freq[a[i]] += 1;
	}

	set<pair<int,int>> st;
	for (int len = 1; len < MXN; ++len) if (freq[len] >= 2)
		st.insert({freq[len], len});

	int q;	cin >> q;
	while (q--) {
		char op;	cin >> op;
		int x;	cin >> x;
		pair<int,int> ele = {freq[x], x};
		if (op == '+') {
			if (freq[x] == 0) freq[x]++;
			else if (freq[x] == 1) {
				freq[x]++, st.insert({freq[x], x});
			} else if (freq[x] > 1) {
				st.erase(ele);
				freq[x]++, st.insert({freq[x], x});
			}
		} else {
			if (freq[x] <= 1) freq[x] = max(0, freq[x]-1);
			if (freq[x] == 2) {
				st.erase(ele);
				freq[x]--;
			} else if (freq[x] > 2) {
				st.erase(ele);
				freq[x]--, st.insert({freq[x], x});
			}
		}

		if (st.empty()) {
			cout << "NO" << el;
			continue;
		};

		auto it1 = st.end();	it1--;
		if (it1->first < 4) {
			cout << "NO" << el;
			continue;
		}
		if (it1->first >= 8) {
			cout << "YES" << el;
			continue;
		}
		if (it1 != st.begin()) {
			if (it1->first - 4 >= 2) {
				auto it2 = prev(it1);
				if (it2->first >= 2) {
					cout << "YES" << el;
					continue;
				}
			}

			auto it2 = prev(it1);
			if (it2->first >= 4) {
				cout << "YES" << el;
				continue;
			}

			int cnt2 = 0;
			if (it2->first >= 2) cnt2 += 1;
			if (it2 != st.begin()) {
				it2 = prev(it2);
				if (it2->first >= 2) cnt2 += 1;
				if (cnt2 == 2) {
					cout << "YES" << el;
					continue;
				}
			}
		}

		cout << "NO" << el;
	}

	return 0;
}
