#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int MAXN = 1e5+5;
char str[MAXN];
int32_t n, memo[MAXN][3][3]; // idx, lastbit, flipstate

int32_t solve(int32_t idx, int32_t last, int32_t flip) {
	if (idx == n) return 0;

	int32_t &ret = memo[idx][last][flip];
	if (~ret) return ret;
	ret = solve(idx + 1, last, flip); // leave

	int32_t curr = str[idx] - '0';

	if (flip == 0) { // take at different states
		if (last != curr)
			ret = max(ret, 1 + solve(idx + 1, curr, flip));
		if (last != (curr ^ 1))
			ret = max(ret, 1 + solve(idx + 1, curr ^ 1, 1));
	} else if (flip == 1) {
		if (last != (curr ^ 1))
			ret = max(ret, 1 + solve(idx + 1, curr ^ 1, flip));
		if (last != curr)
			ret = max(ret, 1 + solve(idx + 1, curr, 2));
	} else {
		if (last != curr) ret = max(ret, 1 + solve(idx + 1, curr, flip));
	}
	
	return ret;
}

int32_t main() {
	scanf("%d", &n);
	scanf("%s", str);
	memset(memo, -1, sizeof memo);
	return printf("%d", solve(0, 2, 0)), 0;
}
