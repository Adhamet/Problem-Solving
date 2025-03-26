#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define fst first
#define scd second

int32_t main() {
	int32_t tc;
	scanf("%d", &tc);
	
	while (tc--) {
		int32_t n;
		scanf("%d", &n);

		int32_t a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

		auto calc = [&](int32_t k) -> pair<int32_t, int32_t> {
			int32_t ndiff = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] == -1) {
					if (i - 1 >= 0 && a[i-1] != -1) ndiff = max(ndiff, abs(k-a[i-1]));
					if (i + 1 < n && a[i+1] != -1) ndiff = max(ndiff, abs(k-a[i+1]));
				}
			}

			return {ndiff, k};
		};

		int32_t l = 1, r = 1e9;
		pair<int32_t, int32_t> missing;
		while (l <= r) { // p1<p2 (dec), p1>p2 (inc)
			int32_t mid = (l + r) >> 1;

			pair<int32_t, int32_t> p1 = calc(mid);
			pair<int32_t, int32_t> p2 = calc(mid - 1);
			if (p1.fst < p2.fst) l = mid + 1, missing = p1;
			else r = mid - 1;
		}

		for (int i = 0; i < n; ++i) if (a[i] == -1) a[i] = missing.scd;
		int32_t diff = 0;
		for (int i = 1; i < n; ++i) diff = max(diff, abs(a[i]-a[i-1]));
		printf("%d %d\n", diff, missing.scd);
	}
	

	return 0;
}
