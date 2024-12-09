#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		// a[j] - j > a[i] - i;
		int n = s.size();
		vector<int> a(n);
		for (int i = 0; i < n; i++) a[i] = (s[i] - '0');
		
		vector<pair<int, int>> vec;
		for (int i = 0; i < n; i++) vec.push_back({a[i], i});

		sort(vec.begin(), vec.end(), [](auto a, auto b) {
			if (a.first - a.second == b.first - b.second) return a.first > b.first;
			return (a.first - a.second) > (b.first - b.second);
		});

		vector<int> c(n);
		for (int i = 0; i < n; i++) c[i] = vec[i].first - abs(i - vec[i].second);
		for (auto num: c) cout << num;
		cout << el;
	}

	return 0;
}
