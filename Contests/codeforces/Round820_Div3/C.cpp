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

		int n = s.size();
		int start = s[0] - 'a', end = s[n - 1] - 'a';

		vector<int> indices[26];
		for (int i = 0; i < n; i++) indices[s[i] - 'a'].push_back(i + 1);

		vector<int> path;
		if (start <= end) {
			for (int i = start; i <= end; i++) {
				for (int idx: indices[i]) path.push_back(idx);
			}
		} else {
			for (int i = start; i >= end; i--) {
				for (int idx: indices[i]) path.push_back(idx);
			}
		}

		int cost = 0;
		for (int i = 1; i < path.size(); i++) {
			cost += abs(s[path[i] - 1] - s[path[i - 1] - 1]);
		}

		cout << cost << " " << path.size() << el;
		for (int idx: path) cout << idx << " ";
		cout << el;
	}

	return 0;
}
