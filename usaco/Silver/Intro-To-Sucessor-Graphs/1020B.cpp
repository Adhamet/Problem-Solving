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

vector<int> succ, ans;
void fillUp(int tortoise, int mu) {
	while (tortoise != mu) {
		ans[tortoise] = ans[mu];
		tortoise = succ[tortoise];
	}
}

void floyd(int x0) {
	int tortoise = succ[x0], hare = succ[succ[x0]];

	while (tortoise != hare) {
		if (ans[tortoise] != -1) {
			fillUp(x0, tortoise);
			return;
		}

		tortoise = succ[tortoise];
		hare = succ[succ[hare]];
	}

	tortoise = x0;
	while (tortoise != hare) tortoise = succ[tortoise], hare = succ[hare];

	int mu = tortoise;
	tortoise = x0;
	while (tortoise != mu) ans[tortoise] = mu, tortoise = succ[tortoise];

	tortoise = mu;
	do {
		ans[tortoise] = tortoise;
		tortoise = succ[tortoise];
	} while (tortoise != mu);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	succ.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> succ[i];

	ans.resize(n + 1, -1);
	for (int i = 1; i <= n; i++) if (ans[i] == -1) {
		floyd(i);
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
