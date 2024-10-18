#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<int> move_result(const vector<int>& toMove) {
	cout << "next ";
	for (size_t i = 0; i < toMove.size() - 1; i++) cout << toMove[i] << " ";
	cout << toMove.back() << '\n';

	int groupNum;
	cin >> groupNum;
	vector<int> groups(10);
	for (int g = 0; g < groupNum; g++) {
		string group;
		cin >> group;
		for (char ch: group) groups[ch - '0'] = g;
	}

	return groups;
}

int main() {
	move_result({0, 1});
	vector<int> groups = move_result({1});
	while (groups[0] != groups[1]) {
		move_result({0, 1});
		groups = move_result({1});
	}

	while (groups[2] != groups[1]) {
		groups = move_result({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}

	cout << "done" << '\n';
}
