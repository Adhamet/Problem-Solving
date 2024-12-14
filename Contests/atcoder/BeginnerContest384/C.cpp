#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	map<int, int> mp = {
		{'A', a}, {'B', b}, {'C', c}, {'D', d}, {'E', e}
	};

	string s = "ABCDE";
	vector<pair<string, int>> list;
	for (int i = 1; i < (1 << 5); i++) {
		int val = 0;
		string subseq = "";
		for (int j = 0; j < 5; j++) {
			if (i & (1 << j)) subseq += s[j], val += mp[s[j]];
		}

		list.push_back({subseq, val});
	}

	sort(list.begin(), list.end(), [](auto a, auto b) {
		if (a.second == b.second) return (a.first < b.first);
		return a.second > b.second;
	});

	int m = list.size();
	for (int i = 0; i < m; i++) cout << list[i].first << el;
	return 0;
}
