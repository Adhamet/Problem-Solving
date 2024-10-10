#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct entry {
	int val, index;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	
	int n;
	cin >> n;

	vector<entry> entries(n);
	for (int i = 0; i < n; i++) {
		cin >> entries[i].val;
		entries[i].index = i;
	}

	sort(entries.begin(), entries.end(), [](entry a, entry b) {
		return (a.val == b.val ? a.index < b.index : a.val < b.val);
	});

	int ans = 1;
	for (int i = 0; i < n; i++) ans = max(ans, 1 + entries[i].index - i);
	cout << ans << el;
	
	return 0;
}
