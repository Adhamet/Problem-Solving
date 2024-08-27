#include <bits/stdc++.h>
using namespace std;
 
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
 
		int from[n], to[n];
 
		fill(from, from + n, 0);
		fill(to, to + n, 0);
 
		from[x - 1] = 1;
 
		while (m--) {
			int dist;
			char dir;
			cin >> dist >> dir;
 
			for (int i = 0; i < n; i++) to[i] = 0;
 
			for (int i = 0; i < n; i++) if (from[i]) {
				if (dir == '0' || dir == '?') to[(i + dist) % n] = 1;
				if (dir == '1' || dir == '?') to[(i + n - dist) % n] = 1;
			}
 
			for (int i = 0; i < n; i++) from[i] = to[i];
		}
 
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += from[i];
 
		cout << cnt << el;
		for (int i = 0; i < n; i++) if (from[i]) {
			cout << i + 1 << " ";
		}
		cout << el;
	}
 
	return 0;
}
