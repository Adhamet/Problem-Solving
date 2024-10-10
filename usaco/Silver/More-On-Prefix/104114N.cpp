#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(n + 4);
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 2; i <= n; i++) if (a[i] < a[i - 1] - m) {
		a[i] = a[i - 1] - m;
	}
	for (int i = n - 1; i > 0; i--) if (a[i] < a[i + 1] - m) {
		a[i] = a[i + 1] - m;
	}

	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << el;

	return 0;
}
