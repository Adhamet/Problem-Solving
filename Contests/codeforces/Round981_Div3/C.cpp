#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<int, int> freq;
		vector<int> a(n);
		for (auto &i: a) cin >> i, freq[i] += 1;
		
		int disturbance = 0;
		for (int i = 1; i < n; i++) if (a[i] == a[i - 1]) {
			disturbance += 1;
		}

		if (disturbance == 0) {
			cout << 0 << el;
			continue;
		} else {
			vector<int> b, c;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] == a[i + 1]) {
d					b = a, c = a;
					int oppB = n - i - 1, oppC = n - i - 1 + 1;
					int distB = 1e9, distC = 1e9;
					if (oppB == i) continue;
					else {
						swap(b[i], oppB);

						distB = 0;
						for (int i = 0; i < n - 1; i++) if (b[i] == b[i + 1]) {
							distB += 1;
						}
					}

					if (oppB == i + 1) continue;
					else {
						swap(c[i], oppC);

						distC = 0;
						for (int i = 0; i < n - 1; i++) if (c[i] == c[i + 1]) {
							distC += 1;
						}
					}

					if (distB <= distC) a = b;
					else a = c;
				}
			}

			int currDist = 0;
			for (int i = 0; i < n; i++) if (a[i] == a[i - 1]) currDist += 1;
			cout << currDist << el;
		}
	}

	return 0;
}
