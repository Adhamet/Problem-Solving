#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	printf("%d\n", 7 * n + 8);
	for (int i = 0; i <= n; ++i) {
		printf("%d %d\n", 2 * i + 0, 2 * i + 0);
		printf("%d %d\n", 2 * i + 1, 2 * i + 0);
		printf("%d %d\n", 2 * i + 2, 2 * i + 0);
		printf("%d %d\n", 2 * i + 0, 2 * i + 1);
		printf("%d %d\n", 2 * i + 0, 2 * i + 2);
		printf("%d %d\n", 2 * i + 1, 2 * i + 2);
		printf("%d %d\n", 2 * i + 2, 2 * i + 1);
	}

	return printf("%d %d", 2 * n + 2, 2 * n + 2), 0;
}
