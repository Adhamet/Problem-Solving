#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t n;
	scanf("%d", &n);
	
	int64_t a[n], sum = 0;
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]), sum += a[i];

	if (sum % 3) printf("%d", 0);
	else {
		int64_t need = (sum / 3);
		int64_t ans = 0, cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (i > 0) a[i] += a[i - 1];
			if (a[i] == 2 * need) ans += cnt;
			if (a[i] == need) cnt += 1;
		}

		printf("%lld", ans);
	}


	return 0;
}
