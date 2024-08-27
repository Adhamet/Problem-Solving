#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 100005;
// const int oo = 1e9 + 20;

int arr[N];
int n, k;

bool can(int val) {
	int last = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (last < arr[i]) {
			last = arr[i] + val - 1;
			cnt++;
		}
	}

	return cnt <= k;
}

int main()	{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];	
		}

		int l = 1, r = 1e9, ans = 0;
		
		while (l <= r) {
			int mid = ( l + r ) / 2;

			if (can(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		cout << ans << el;
	}

	return 0;
}
