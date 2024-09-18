#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> sheeps;
		for (int i = 0; i < n; i++) if (s[i] == '*') sheeps.push_back(i);
		if (sheeps.size() == 0 || sheeps.size() == 1) {
			cout << 0 << el;
			continue;
		}

		ll moves = 0;
		int ms = sheeps.size() / 2, msp = sheeps[ms];
		for (int i = 0; i < sheeps.size(); i++) moves += abs(sheeps[i] - (msp - (ms - i)));
		cout << moves << el;
	}

	return 0;
}
