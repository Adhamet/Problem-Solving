#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, id, solved;
	cin >> n;
	vector<array<int, 2>> teams(n);
	for (int i = 0; i < n; i++) {
		cin >> id >> solved;
		teams[i][0] = id, teams[i][1] = solved;
	}

	stable_sort(teams.begin(), teams.end(), [](auto& a, auto& b) {
		return a[1] > b[1];
	});

	for (auto pr: teams) cout << pr[0] << " " << pr[1] << el;
	return 0;
}
