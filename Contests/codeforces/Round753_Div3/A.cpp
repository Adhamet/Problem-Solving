#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	int t;	scanf("%d", &t);
	while (t--) {
		char cs[105], ct[105];
		scanf("%s%s", cs, ct);
		int pos[26];
		for (int i = 0; cs[i] != '\0'; ++i) pos[cs[i] - 'a'] = i;
		int ans = 0;
		for (int i = 0; i < ct[i+1] != '\0'; ++i) ans += abs(pos[ct[i+1] - 'a'] - pos[ct[i] - 'a']);
		printf("%d\n", ans);
	}
	return 0;
}
