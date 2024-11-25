#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	bool impossible = false;
	string s, t;
	cin >> s >> t;
	map<int, int> sMp, tMp;
	for (char c: s) sMp[c] += 1;
	for (char c: t) tMp[c] += 1;
	for (auto [ch, freq]: tMp) {
		if (sMp[ch] < freq) {
			impossible = true;
			break;
		}
	}

	if (!impossible) {
		int i = 0, j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j]) j += 1;
			i += 1;
		}

		if (j == t.size()) cout << "automaton";
		else if (s.size() == t.size()) cout << "array";
		else cout << "both";
	} else cout << "need tree";
	return 0;
}
