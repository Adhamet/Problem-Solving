#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t tc;
	scanf("%d", &tc);
	while (tc--) {
		int64_t n;
		scanf("%lld", &n);
	
		vector<int64_t> a(n);
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	
		int64_t cnt = 0;
		for (int i = 1; i < n; ++i) {
			int64_t l = 0, r = i - 1, curr = i;
	
			while (l <= r) {
				int64_t mid = (l + r) >> 1;
				if (a[mid] + a[i] > i + 1) {
					curr = mid;
					r = mid - 1;
				} else l = mid + 1;
			}

			cnt += (i - curr);
		}	
	
		printf("%lld\n", cnt);
	}
	return 0;
}
