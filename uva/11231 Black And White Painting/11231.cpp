#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	i64 x, y, z;
	while (cin >> x >> y >> z && (x || y || z)) {
		if (z == 0) cout << (x - 7) * (y - 7) / 2 << el;
		else cout << ((x - 7) * (y - 7) + 1) / 2 << el;
	}

	return 0;
}
