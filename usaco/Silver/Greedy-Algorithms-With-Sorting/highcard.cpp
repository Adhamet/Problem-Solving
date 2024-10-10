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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	setIO("highcard");

	int n;
	cin >> n;

	unordered_map<int, bool> elsie;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		elsie[x] = true;
	}

	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= 2 * n; i++) {
		if (elsie[i]) q.push(i);
		else {
			if (!q.empty()) {
				q.pop();
				cnt += 1;
			}
		}
	}
	cout << cnt << el;

	return 0;
}
