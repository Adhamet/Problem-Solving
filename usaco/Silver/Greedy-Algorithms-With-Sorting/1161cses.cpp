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

	int n, k;
	cin >> n >> k;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;

		pq.push(x);
	}

	ll ans = 0;
	for (int i = 1; i < k; i++) {
		int a = pq.top();
		pq.pop();

		int b = pq.top();
		pq.pop();

		pq.push(a + b);
		ans += (a + b);
	}
	cout << ans << el;
	
	return 0;
}
