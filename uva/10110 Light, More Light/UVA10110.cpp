#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	unsigned int n;
	while (cin >> n && n) {
		unsigned int sqr = sqrt(n);
		cout << (sqr * sqr == n? "yes\n": "no\n");
	}

	return 0;
}
