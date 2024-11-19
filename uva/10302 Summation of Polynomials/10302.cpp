#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	const int MAXN = 50005;
	ll sums[MAXN];
	auto cube = [&](ll num) { return num * num * num; };
	sums[1] = 1, sums[2] = 9;
	for (int i = 3; i <= MAXN - 4; i++) sums[i] = sums[i - 1] + cube(i);

	int num;
	while (cin >> num) cout << sums[num] << el;
	return 0;
}
