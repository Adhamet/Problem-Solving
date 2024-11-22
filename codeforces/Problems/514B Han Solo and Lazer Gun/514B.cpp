#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

struct pt {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	int n;
	pt gun, trooper;
	cin >> n >> gun.x >> gun.y;

	int cnt = 0;
	set<pair<int, int>> stLine;
	for (int i = 0; i < n; i++) {
		cin >> trooper.x >> trooper.y;
		int dy = trooper.y - gun.y, dx = trooper.x - gun.x;
		int _g = __gcd(dy, dx);
		dy /= _g, dx /= _g;

		if (!stLine.count({dy, dx})) cnt += 1, stLine.insert({dy, dx});
	}

	cout << cnt << el;
	return 0;
}
