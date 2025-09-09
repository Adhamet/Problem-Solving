#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d;
	if (a <= c) {
		while (a <= c) {
			if (a + b <= c) a += b, e = a;
			else { e = c;	break; }
			if (c - d >= a) c -= d, e = c;
			else { e = a;	break; }
		}

		cout << e << el;
	} else cout << a << el;
	return 0;
}
