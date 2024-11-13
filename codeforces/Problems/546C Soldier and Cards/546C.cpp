#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k1, k2;
	cin >> n;

	cin >> k1;
	deque<int> v1(k1);
	for (int i = 0; i < k1; i++) cin >> v1[i];
	cin >> k2;
	deque<int> v2(k2);
	for (int i = 0; i < k2; i++) cin >> v2[i];

	int fights = 0;
	set<pair<deque<int>, deque<int>>> seenStates;

	while (!v1.empty() && !v2.empty()) {
		if (seenStates.count({v1, v2})) {
			cout << -1 << el;
			return 0;
		}

		seenStates.insert({v1, v2});
		int card1 = v1.front();
		int card2 = v2.front();
		v1.pop_front();
		v2.pop_front();

		if (card1 > card2) {
			v1.push_back(card2);
			v1.push_back(card1);
		} else {
			v2.push_back(card1);
			v2.push_back(card2);
		}

		fights++;

		if (v1.empty()) {
			cout << fights << " 2" << el;
			return 0;
		} else if (v2.empty()) {
			cout << fights << " 1" << el;
			return 0;
		}
	}
	return 0;
}
