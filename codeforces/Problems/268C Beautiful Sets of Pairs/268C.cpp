#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t n, m, k;
	scanf("%d%d", &n, &m);
	k = (n < m ? n: m);
	printf("%d\n", k + 1);
	for (int i = 0; i <= k; ++i) printf("%d %d\n", i, k - i);
	return 0;
}
