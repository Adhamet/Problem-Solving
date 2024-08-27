#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> p(n);
		int maxEle = 0, maxIdx = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			if (i != 0 && p[i] > maxEle) {
				maxEle = p[i];
				maxIdx = i;
			}
		}

		if (n == 1) {
			cout << p[0] << el;
			continue;
		}

		if (maxIdx == n - 1) {
			cout << p[n - 1] << " ";
			
			int l = n - 2;
			while (l >= 0 && p[l] > p[0]) cout << p[l--] << " ";

			for (int i = 0; i <= l; i++) cout << p[i] << " ";
		} else {
			for (int i = maxIdx; i < n; i++) cout << p[i] << " ";
			cout << p[maxIdx - 1] << " ";
			
			int l = maxIdx - 2;
			while (l >= 0 && p[0] < p[l]) cout << p[l--] << " ";
			
			for (int i = 0; i <= l; i++) cout << p[i] << " ";
		}
		cout << el;
	}

	return 0;
}
