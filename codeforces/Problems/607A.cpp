#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int32_t oo = 1e9+7;
int32_t n;
int64_t recurse(int idx) {
	if (idx < 0) return 0;

	int64_t &ret = memo[idx];
	if (~ret) return ret;
	ret = oo;

	int32_t l = 0, r = idx - 1, destroy = -1;
	while (l <= r) {
		int32_t mid = (l + r) >> 1;
		if (a[mid] >= idx - b[idx]) r = mid - 1, destroy = mid;
		else l = mid + 1;
	}

	if (~destroy) // pick
		ret = min(ret, recurse(destroy - 1) + (idx - destroy));
	ret = min(ret, recurse(idx - 1) + (n - idx)); // leave
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	

	return 0;
}
