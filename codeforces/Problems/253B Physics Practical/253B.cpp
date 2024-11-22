#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	vector<int> measurements(n);
	for (int &x : measurements) cin >> x;
	sort(measurements.begin(), measurements.end());

	int maxValidSize = 0;
	for (int left = 0, right = 0; right < n; ++right) {
		while (measurements[right] > 2 * measurements[left]) ++left;
		maxValidSize = max(maxValidSize, right - left + 1);
	}

	cout << n - maxValidSize << '\n';
	return 0;
}
