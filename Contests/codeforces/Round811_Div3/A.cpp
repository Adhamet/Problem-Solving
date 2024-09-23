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

	int t;
	cin >> t;

	while (t--) {
		int n, H, M;
		cin >> n >> H >> M;

		int mn = 24 * 60;
		for (int i = 0; i < n; i++) {
			int h, m;
			cin >> h >> m;

			int currentTime = H * 60 + M;
			int alarmTime = h * 60 + m;

			int timeDiff;
			if (alarmTime >= currentTime) timeDiff = alarmTime - currentTime;
			else timeDiff = (24 * 60 - currentTime) + alarmTime;

			mn = min(mn, timeDiff);
		}

		int hours = mn / 60;
		int minutes = mn % 60;
		cout << hours << " " << minutes << el;
	}

	return 0;
}
