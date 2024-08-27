#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	ll sum = 0;
	vector<int> a(n + 1);
	vector<bool> vis(n + 1, false);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sum /= (n / 2); 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;

			for (int j = i + 1; j <= n; j++) {
				if (!vis[j] && (a[i] + a[j]) == sum) {
					vis[j] = true;
					cout << i << " " << j << el;
					break;
				}
			}
		}
	}

	return 0;
}
