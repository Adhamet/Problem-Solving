#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'

using pi = pair<int, int>;

const int N = 1e4 + 5;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	queue<pi> q;
	q.push({n, 0});

	vector<int> vis(N, false);
	while (!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (node == m) {
			cout << cnt << el;
			break;
		}
		
		vis[node] = true;
		
		int val1 = node - 1, val2 = node * 2;
		if (val1 > 0 && !vis[val1]) q.push({val1, cnt + 1});
		if (val2 < N && !vis[val2]) q.push({val2, cnt + 1});
	}

	return 0;
}
